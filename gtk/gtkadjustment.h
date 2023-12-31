/* GTK - The GIMP Toolkit
 * Copyright (C) 1995-1997 Peter Mattis, Spencer Kimball and Josh MacDonald
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Modified by the GTK+ Team and others 1997-2000.  See the AUTHORS
 * file for a list of people on the GTK+ Team.  See the ChangeLog
 * files for a list of changes.  These files are distributed with
 * GTK+ at ftp://ftp.gtk.org/pub/gtk/.
 */

#pragma once

#if !defined (__GTK_H_INSIDE__) && !defined (GTK_COMPILATION)
#error "Only <gtk/gtk.h> can be included directly."
#endif

#include <gdk/gdk.h>
#include <gtk/gtktypes.h>

G_BEGIN_DECLS

#define GTK_TYPE_ADJUSTMENT                  (gtk_adjustment_get_type ())
#define GTK_ADJUSTMENT(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_ADJUSTMENT, GtkAdjustment))
#define GTK_ADJUSTMENT_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), GTK_TYPE_ADJUSTMENT, GtkAdjustmentClass))
#define GTK_IS_ADJUSTMENT(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_ADJUSTMENT))
#define GTK_IS_ADJUSTMENT_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), GTK_TYPE_ADJUSTMENT))
#define GTK_ADJUSTMENT_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_ADJUSTMENT, GtkAdjustmentClass))


typedef struct _GtkAdjustmentClass    GtkAdjustmentClass;

struct _GtkAdjustment
{
  GInitiallyUnowned parent_instance;
};

struct _GtkAdjustmentClass
{
  GInitiallyUnownedClass parent_class;

  void (* changed)       (GtkAdjustment *adjustment);
  void (* value_changed) (GtkAdjustment *adjustment);

  /* Padding for future expansion */
  void (*_gtk_reserved1) (void);
  void (*_gtk_reserved2) (void);
  void (*_gtk_reserved3) (void);
  void (*_gtk_reserved4) (void);
};


GDK_AVAILABLE_IN_ALL
GType      gtk_adjustment_get_type              (void) G_GNUC_CONST;
GDK_AVAILABLE_IN_ALL
GtkAdjustment*   gtk_adjustment_new             (double           value,
                                                 double           lower,
                                                 double           upper,
                                                 double           step_increment,
                                                 double           page_increment,
                                                 double           page_size);

GDK_AVAILABLE_IN_ALL
void       gtk_adjustment_clamp_page            (GtkAdjustment   *adjustment,
                                                 double           lower,
                                                 double           upper);

GDK_AVAILABLE_IN_ALL
double     gtk_adjustment_get_value             (GtkAdjustment   *adjustment);
GDK_AVAILABLE_IN_ALL
void       gtk_adjustment_set_value             (GtkAdjustment   *adjustment,
                                                 double           value);
GDK_AVAILABLE_IN_ALL
double     gtk_adjustment_get_lower             (GtkAdjustment   *adjustment);
GDK_AVAILABLE_IN_ALL
void       gtk_adjustment_set_lower             (GtkAdjustment   *adjustment,
                                                 double           lower);
GDK_AVAILABLE_IN_ALL
double     gtk_adjustment_get_upper             (GtkAdjustment   *adjustment);
GDK_AVAILABLE_IN_ALL
void       gtk_adjustment_set_upper             (GtkAdjustment   *adjustment,
                                                 double           upper);
GDK_AVAILABLE_IN_ALL
double     gtk_adjustment_get_step_increment    (GtkAdjustment   *adjustment);
GDK_AVAILABLE_IN_ALL
void       gtk_adjustment_set_step_increment    (GtkAdjustment   *adjustment,
                                                 double           step_increment);
GDK_AVAILABLE_IN_ALL
double     gtk_adjustment_get_page_increment    (GtkAdjustment   *adjustment);
GDK_AVAILABLE_IN_ALL
void       gtk_adjustment_set_page_increment    (GtkAdjustment   *adjustment,
                                                 double           page_increment);
GDK_AVAILABLE_IN_ALL
double     gtk_adjustment_get_page_size         (GtkAdjustment   *adjustment);
GDK_AVAILABLE_IN_ALL
void       gtk_adjustment_set_page_size         (GtkAdjustment   *adjustment,
                                                 double           page_size);

GDK_AVAILABLE_IN_ALL
void       gtk_adjustment_configure             (GtkAdjustment   *adjustment,
                                                 double           value,
                                                 double           lower,
                                                 double           upper,
                                                 double           step_increment,
                                                 double           page_increment,
                                                 double           page_size);
GDK_AVAILABLE_IN_ALL
double     gtk_adjustment_get_minimum_increment (GtkAdjustment   *adjustment);

G_DEFINE_AUTOPTR_CLEANUP_FUNC(GtkAdjustment, g_object_unref)

G_END_DECLS

