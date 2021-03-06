/* SPU specific support for 32-bit ELF.

   Copyright 2006, 2007, 2008 Free Software Foundation, Inc.

   This file is part of BFD, the Binary File Descriptor library.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */

/* Extra info kept for SPU sections.  */

struct spu_elf_stack_info;

struct _spu_elf_section_data
{
  struct bfd_elf_section_data elf;

  union {
    /* Info kept for input sections.  */
    struct {
      /* Stack analysis info kept for this section.  */
      struct spu_elf_stack_info *stack_info;
    } i;

    /* Info kept for output sections.  */
    struct {
      /* Non-zero for overlay output sections.  */
      unsigned int ovl_index;
      unsigned int ovl_buf;
    } o;
  } u;
};

#define spu_elf_section_data(sec) \
  ((struct _spu_elf_section_data *) elf_section_data (sec))

struct _ovl_stream
{
  const void *start;
  const void *end;
};

extern void spu_elf_plugin (int);
extern bfd_boolean spu_elf_open_builtin_lib (bfd **,
					     const struct _ovl_stream *);
extern bfd_boolean spu_elf_create_sections (struct bfd_link_info *, int, int);
extern bfd_boolean spu_elf_find_overlays (struct bfd_link_info *);
extern int spu_elf_size_stubs (struct bfd_link_info *,
			       void (*) (asection *, asection *, const char *),
			       int);
extern bfd_boolean spu_elf_build_stubs (struct bfd_link_info *, int);
extern asection *spu_elf_check_vma (struct bfd_link_info *, int,
				    unsigned int, unsigned int, unsigned int,
				    unsigned int, int, void (*) (void),
				    FILE *(*) (void), void (*) (void));
