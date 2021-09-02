#define JC_VORONOI_IMPLEMENTATION
#include "voronoi_module.h"

void Voronoi::_bind_methods() {
  ClassDB::bind_method(D_METHOD("generate_voronoi_cells", "points", "extents"),
                       &Voronoi::generate_voronoi_cells);
}

jcv_point convert(const Vector2 &vec) { return {vec[0], vec[1]}; }

Vector2 convert(const jcv_point &point) {
  return Vector2(point.x, point.y);
}

Vector<Variant> extract_voronoi_cells(const jcv_diagram &voronoiDiagram) {
	auto voronoi_cells = Vector<Variant>();
	const auto *sites = jcv_diagram_get_sites(&voronoiDiagram);
	for (int i = 0; i < voronoiDiagram.numsites; ++i) {
		const auto &site = sites[i];
		const auto &center = convert(site.p);
		const auto *edge = site.edges;
		auto outline_points = PoolVector2Array();
		auto global_outline_points = PoolVector2Array();
		auto neighbor_indices = PoolIntArray();
		while (edge) {
			// Check that edge is not degenerate
			if (!jcv_point_eq(&edge->pos[0], &edge->pos[1])) {
				const auto global_point = convert(edge->pos[0]);
				global_outline_points.push_back(global_point);
				outline_points.push_back(global_point - center);
				const auto *neighbor = edge->neighbor;
				neighbor_indices.push_back(neighbor ? neighbor->index : -1);
			}
			edge = edge->next;
		}
		auto *voronoi_cell = new VoronoiCell();
		voronoi_cell->set_center(center);
		voronoi_cell->set_cell_index(site.index);
		voronoi_cell->set_neighbor_indices(neighbor_indices);
		voronoi_cell->set_outline_points(outline_points);
		voronoi_cell->set_global_outline_points(global_outline_points);
		voronoi_cells.push_back(voronoi_cell);
	}
	return voronoi_cells;
}

void* useralloc(void* ctx, size_t size) {
    return memalloc(size);
}

void userfree(void* ctx, void* ptr) {
    return memfree(ptr);
}

Vector<Variant> Voronoi::generate_voronoi_cells(const PoolVector2Array &points,
                                      const Rect2 &extents) const {
  jcv_diagram voronoiDiagram;
  memset(&voronoiDiagram, 0, sizeof(jcv_diagram));
  jcv_rect rect = {convert(extents.get_position()),
                   convert(extents.get_position() + extents.get_size())};
  jcv_point *jcv_points = memnew_arr(jcv_point, points.size());
  for (int i = 0; i < points.size(); i++) {
    jcv_points[i] = convert(points[i]);
  }
  jcv_diagram_generate_useralloc(
    points.size(),
    jcv_points,
    &rect,
    nullptr,
    nullptr,
    &useralloc,
    &userfree,
    &voronoiDiagram
  );
  const auto &voronoiCells = extract_voronoi_cells(voronoiDiagram);
  jcv_diagram_free(&voronoiDiagram);
  memdelete_arr(jcv_points);
  return voronoiCells;
}
