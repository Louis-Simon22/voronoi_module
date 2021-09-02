#ifndef VORONOICELL_H
#define VORONOICELL_H

#include <core/object.h>

class VoronoiCell : public Object {
public:
  GDCLASS(VoronoiCell, Object);

protected:
  static void _bind_methods();

public:
  int get_cell_index() const;
  void set_cell_index(int cell_index);
  const PoolIntArray &get_neighbor_indices() const;
  void set_neighbor_indices(const PoolIntArray &neighbor_indices);
  const PoolVector2Array &get_outline_points() const;
  const PoolVector2Array &get_global_outline_points() const;
  void set_outline_points(const PoolVector2Array &outline_points);
  void set_global_outline_points(const PoolVector2Array &global_outline_points);
  const Vector2 &get_center() const;
  void set_center(const Vector2 &center);

private:
  int cell_index;
  PoolIntArray neighbor_indices;
  Vector2 center;
  PoolVector2Array outline_points;
  PoolVector2Array global_outline_points;
};

#endif // VORONOICELL_H
