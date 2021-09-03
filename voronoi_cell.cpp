#include "voronoi_cell.h"

VoronoiCell::VoronoiCell(int cell_index, const Vector2 &center, const PoolIntArray &neighbor_indices,
		const PoolVector2Array &vertices_global) :
		cell_index(cell_index), center(center), neighbor_indices(neighbor_indices),
        vertices_global(vertices_global)
{}

void VoronoiCell::_bind_methods() {
  ClassDB::bind_method(D_METHOD("index"),
                       &VoronoiCell::get_cell_index);
  ClassDB::bind_method(D_METHOD("neighbor_indices"),
                       &VoronoiCell::get_neighbor_indices);
  ClassDB::bind_method(D_METHOD("vertices"),
                       &VoronoiCell::get_vertices_local);
  ClassDB::bind_method(D_METHOD("vertices_global"),
                       &VoronoiCell::get_vertices_global);
  ClassDB::bind_method(D_METHOD("center"), &VoronoiCell::get_center);
}

int VoronoiCell::get_cell_index() const { return this->cell_index; }

const PoolIntArray &VoronoiCell::get_neighbor_indices() const {
  return this->neighbor_indices;
}

PoolVector2Array VoronoiCell::get_vertices_local() const {
  auto vertices_local = PoolVector2Array();
  vertices_local.resize(vertices_global.size());
  for (std::size_t i = 0; i < vertices_global.size(); i++) {
    vertices_local.set(i, vertices_global[i] - center);
  }
  return vertices_local;
}

const PoolVector2Array &VoronoiCell::get_vertices_global() const {
  return this->vertices_global;
}

const Vector2 &VoronoiCell::get_center() const { return this->center; }
