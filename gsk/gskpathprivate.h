/*
 * Copyright © 2020 Benjamin Otte
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 *
 * Authors: Benjamin Otte <otte@gnome.org>
 */


#pragma once

#include "gskpath.h"

#include "gskpathopprivate.h"

G_BEGIN_DECLS

typedef enum
{
  GSK_PATH_FLAT,
  GSK_PATH_CLOSED
} GskPathFlags;

typedef struct _GskContour GskContour;
typedef struct _GskRealPathPoint GskRealPathPoint;

/* Same as Skia, so looks like a good value. ¯\_(ツ)_/¯ */
#define GSK_PATH_TOLERANCE_DEFAULT (0.5)

GskPath *               gsk_path_new_from_contours              (const GSList           *contours);

gsize                   gsk_path_get_n_contours                 (const GskPath          *self);
const GskContour *      gsk_path_get_contour                    (const GskPath          *self,
                                                                 gsize                   i);

GskPathFlags            gsk_path_get_flags                      (const GskPath          *self);

gboolean                gsk_path_foreach_with_tolerance         (GskPath                *self,
                                                                 GskPathForeachFlags     flags,
                                                                 double                  tolerance,
                                                                 GskPathForeachFunc      func,
                                                                 gpointer                user_data);


void                    gsk_path_builder_add_contour            (GskPathBuilder         *builder,
                                                                 GskContour             *contour);

void                    gsk_path_builder_svg_arc_to             (GskPathBuilder         *builder,
                                                                 float                   rx,
                                                                 float                   ry,
                                                                 float                   x_axis_rotation,
                                                                 gboolean                large_arc,
                                                                 gboolean                positive_sweep,
                                                                 float                   x,
                                                                 float                   y);


G_END_DECLS

