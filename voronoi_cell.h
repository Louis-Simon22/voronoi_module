#ifndef VORONOICELL_H
#define VORONOICELL_H

#include <core/object.h>

class VoronoiCell : public Object {
public:
  GDCLASS(VoronoiCell, Object);

public:
  VoronoiCell() = default;
  VoronoiCell(int cell_index, const Vector2 &center, const PoolIntArray &neighbor_indices,
	  const PoolVector2Array &vertices_global);
  ~VoronoiCell() = default;

protected:
  static void _bind_methods();

public:
  int get_cell_index() const;
  const PoolIntArray &get_neighbor_indices() const;
  PoolVector2Array get_vertices_local() const;
  const PoolVector2Array &get_vertices_global() const;
  const Vector2 &get_center() const;

private:
  int cell_index;
  Vector2 center;
  PoolIntArray neighbor_indices;
  PoolVector2Array vertices_global;
};

#endif // VORONOICELL_H
