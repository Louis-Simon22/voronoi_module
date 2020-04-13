#ifndef VORONOIMODULE_H
#define VORONOIMODULE_H

#include "core/reference.h"

#include "jc_voronoi.h"

#include "voronoi_cell.h"

class Voronoi : public Reference {
  GDCLASS(Voronoi, Reference);

protected:
  static void _bind_methods();

public:
  Array generate_voronoi_cells(const Vector<Vector2> &points,
                               const Rect2 &extents);

private:
  jcv_point convert(const Vector2 &vec);
  Vector2 convert(const jcv_point &point);
  Array extract_voronoi_cells(const jcv_diagram &voronoiDiagram);
};

#endif // VORONOIMODULE_H
