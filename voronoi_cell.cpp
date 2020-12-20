#include "voronoi_cell.h"

void VoronoiCell::_bind_methods() {
  ClassDB::bind_method(D_METHOD("get_cell_index"),
                       &VoronoiCell::get_cell_index);
  ClassDB::bind_method(D_METHOD("get_neighbor_indices"),
                       &VoronoiCell::get_neighbor_indices);
  ClassDB::bind_method(D_METHOD("get_outline_points"),
                       &VoronoiCell::get_outline_points);
  ClassDB::bind_method(D_METHOD("get_center"), &VoronoiCell::get_center);
}

int VoronoiCell::get_cell_index() const { return this->cell_index; }

void VoronoiCell::set_cell_index(int cell_index) {
  this->cell_index = cell_index;
}

const Array &VoronoiCell::get_neighbor_indices() const {
  return this->neighbor_indices;
}

void VoronoiCell::set_neighbor_indices(const Array& neighbor_indices) {
  this->neighbor_indices = neighbor_indices;
}

const Array &VoronoiCell::get_outline_points() const {
  return this->outline_points;
}

void VoronoiCell::set_outline_points(const Array &outline_points){
  this->outline_points = outline_points;
}

const Vector2 &VoronoiCell::get_center() const { return this->center; }

void VoronoiCell::set_center(const Vector2 &center) { this->center = center; }
