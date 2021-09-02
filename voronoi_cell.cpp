#include "voronoi_cell.h"

void VoronoiCell::_bind_methods() {
  ClassDB::bind_method(D_METHOD("get_cell_index"),
                       &VoronoiCell::get_cell_index);
  ClassDB::bind_method(D_METHOD("get_neighbor_indices"),
                       &VoronoiCell::get_neighbor_indices);
  ClassDB::bind_method(D_METHOD("get_outline_points"),
                       &VoronoiCell::get_outline_points);
  ClassDB::bind_method(D_METHOD("get_global_outline_points"),
                       &VoronoiCell::get_global_outline_points);
  ClassDB::bind_method(D_METHOD("get_center"), &VoronoiCell::get_center);
}

int VoronoiCell::get_cell_index() const { return this->cell_index; }

void VoronoiCell::set_cell_index(int cell_index) {
  this->cell_index = cell_index;
}

const PoolIntArray &VoronoiCell::get_neighbor_indices() const {
  return this->neighbor_indices;
}

void VoronoiCell::set_neighbor_indices(const PoolIntArray &neighbor_indices) {
  this->neighbor_indices = neighbor_indices;
}

const PoolVector2Array &VoronoiCell::get_outline_points() const {
  return this->outline_points;
}

const PoolVector2Array &VoronoiCell::get_global_outline_points() const {
  return this->global_outline_points;
}

void VoronoiCell::set_outline_points(const PoolVector2Array &outline_points) {
  this->outline_points = outline_points;
}

void VoronoiCell::set_global_outline_points(const PoolVector2Array &global_outline_points) {
  this->global_outline_points = global_outline_points;
}

const Vector2 &VoronoiCell::get_center() const { return this->center; }

void VoronoiCell::set_center(const Vector2 &center) { this->center = center; }
