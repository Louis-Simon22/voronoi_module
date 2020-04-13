#ifndef VORONOICELL_H
#define VORONOICELL_H

#include "core/reference.h"

class VoronoiCell : public Reference {
public:
  GDCLASS(VoronoiCell, Reference);

protected:
  static void _bind_methods();

public:
  int get_cell_index() const;
  void set_cell_index(int cell_index);
  const Array &get_neighbor_indices() const;
  void add_neighbor_index(int neighbor_index);
  const Array &get_outline_points() const;
  void add_outline_point(const Vector2 &point);
  const Vector2 &get_center() const;
  void set_center(const Vector2 &center);

private:
  int cell_index;
  Array neighbor_indices;
  Vector2 center;
  Array outline_points;
};

#endif // VORONOICELL_H
