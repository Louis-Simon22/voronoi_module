#ifndef VORONOIMODULE_H
#define VORONOIMODULE_H

#include <core/reference.h>
#include <core/vector.h>
#include <core/variant.h>

#include "jc_voronoi.h"

#include "voronoi_cell.h"

class Voronoi : public Reference {
  GDCLASS(Voronoi, Reference);

public:
  Voronoi() = default;
  ~Voronoi() = default;

protected:
  static void _bind_methods();

public:
  Vector<Variant> generate_voronoi_cells(const PoolVector2Array &points, const Rect2 &extents) const;
};

#endif // VORONOIMODULE_H
