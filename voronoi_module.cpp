#define JC_VORONOI_IMPLEMENTATION
#include "voronoi_module.h"

void Voronoi::_bind_methods() {
  ClassDB::bind_method(D_METHOD("generate_voronoi_cells", "points", "extents"),
                       &Voronoi::generate_voronoi_cells);
}

jcv_point Voronoi::convert(const Vector2 &vec) { return {vec[0], vec[1]}; }
Vector2 Voronoi::convert(const jcv_point &point) {
  return Vector2(point.x, point.y);
}

Array Voronoi::generate_voronoi_cells(const Vector<Vector2> &points,
                                      const Rect2 &extents) {
  jcv_diagram voronoiDiagram;
  memset(&voronoiDiagram, 0, sizeof(jcv_diagram));
  jcv_rect rect = {convert(extents.get_position()),
                   convert(extents.get_position() + extents.get_size())};
  jcv_point *jcv_points = new jcv_point[points.size()];
  for (int i = 0; i < points.size(); i++) {
    jcv_points[i] = convert(points[i]);
  }
  jcv_diagram_generate(points.size(), jcv_points, &rect, 0, &voronoiDiagram);
  const auto &voronoiCells = extract_voronoi_cells(voronoiDiagram);
  jcv_diagram_free(&voronoiDiagram);
  delete[] jcv_points;
  return voronoiCells;
}

Array Voronoi::extract_voronoi_cells(const jcv_diagram &voronoiDiagram) {
  auto voronoi_cells = Array();
  const auto *sites = jcv_diagram_get_sites(&voronoiDiagram);
  for (int i = 0; i < voronoiDiagram.numsites; ++i) {
    const auto &site = sites[i];
    const auto &center = convert(site.p);
    const auto *edge = site.edges;
    auto *voronoi_cell = new VoronoiCell();
    voronoi_cell->set_center(center);
    voronoi_cell->set_cell_index(site.index);
    while (edge) {
      // Check if edge is degenerate
      if (!jcv_point_eq(&edge->pos[0], &edge->pos[1])) {
        const auto &center_relative_point = convert(edge->pos[0]) - center;
        voronoi_cell->add_outline_point(center_relative_point);
        const auto *neighbor = edge->neighbor;
        if (neighbor) {
          voronoi_cell->add_neighbor_index(neighbor->index);
        }
      }
      edge = edge->next;
    }
    voronoi_cells.push_back(Variant(voronoi_cell));
  }
  return voronoi_cells;
}
