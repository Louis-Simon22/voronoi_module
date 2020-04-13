#include "register_types.h"

#include "core/class_db.h"
#include "voronoi_module.h"
#include "voronoi_cell.h"

void register_voronoi_module_types() {
  ClassDB::register_class<Voronoi>();
  ClassDB::register_class<VoronoiCell>();
}

void unregister_voronoi_module_types() {}