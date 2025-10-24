#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include "libft.h"

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>
# include <math.h>

# define EPSILON	0.001

# define MAX	15

# define POINT	1.0
# define VECTOR	0.0

//# define WIDTH	800
//# define HEIGHT 800
# define WIDTH	1400
# define HEIGHT 1400



# define MAX_RECURSION	5

// MATH //
typedef struct s_tuple
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_tuple;

typedef t_tuple	t_point;
typedef t_tuple	t_vec;

typedef struct s_mat2
{
	float	mat[2][2];
}	t_mat2;
typedef struct s_mat3
{
	float	mat[3][3];
}	t_mat3;
typedef struct s_mat4
{
	float	mat[4][4];
}	t_mat4;

enum {
	XY, XZ, YX, YZ, ZX, ZY
};

typedef t_tuple	t_color;
///////////////////////

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}	t_texture;

typedef struct s_tex_list
{
	t_texture			*tex;
	struct s_tex_list	*next;
}	t_tex_list;

typedef struct s_light
{
	int			vsteps;
	int			usteps;
	int			samples;
	t_vec		uvec;
	t_vec		vvec;
	t_point	position;
	t_color	brightness;
	t_color	color;
	t_point	corner;
	float		jitter_by;
}	t_light;

typedef struct s_pair
{
	float	u;
	float	v;
}	t_pair;

enum e_direction
{
	LEFT, RIGHT, FRONT, BACK, UP, DOWN
};

typedef struct s_cube_color
{
	t_color	main;
	t_color	ul;
	t_color	ur;
	t_color	bl;
	t_color	br;
}	t_cube_color;

typedef struct s_cube_face
{
	int			face;
	union
	{
		t_cube_color	c;
		t_texture		*tex;
	};
}	t_cube_face;

typedef struct s_uv_checkers
{
	float			width;
	float			height;
	t_color			c1;
	t_color			c2;
}	t_uv_checkers;

typedef enum e_uv_type
{
	TEXTURE,
	MAPPED_CHECKERS,
	CUBE_COLORS,
	CUBE_TEXTURES
}	t_uv_type;

typedef struct u_uv_pattern
{
	t_uv_type	uv_type;
	char		*texture_path;
	union
	{
		t_texture		*tex;			// TEXTURE, CUBE_TEXURES
		t_uv_checkers	checkers;
		t_cube_face		cube_face;
	};
}	t_uv_pattern;

typedef enum e_simp_pat_type
{
	STRIPE,
	GRADIENT,
	RING,
	CHECKER
}	t_simp_pat_type;

typedef struct s_simple_pattern
{
	t_simp_pat_type	simp_type;
	t_color			c1;
	t_color			c2;
}	t_simple_pattern;

typedef enum e_pattern_type
{
	EMPTY,
	SIMPLE,
	UV_PAT,
}	t_pattern_type;

typedef struct s_pattern
{
	t_pattern_type		type;
	t_mat4				trans;
	union
	{
		t_simple_pattern	simp_pat;
		t_uv_pattern		uv_pat;
	};
}	t_pattern;

typedef struct s_material
{
	t_color		color;
	t_color		effective_color;
	float		ambient;
	float		diffuse;
	float		specular;
	float		shininess;
	float		reflective;
	float		transparency;
	float		refractive_index;
	t_pattern	pattern;
}	t_material;

// OBJECTS //
typedef struct s_discriminant
{
	float	a;
	float	b;
	float	c;
	float	discriminant;
}	t_discriminant;

typedef struct s_sphere
{
	t_point	origin;
	float	radius;
}	t_sphere;

typedef struct s_plane
{
	t_vec	normal;
}	t_plane;

typedef struct s_cylinder
{
	float	min;
	float	max;
	bool	closed;
}	t_cylinder;

typedef struct s_cone
{
	float	min;
	float	max;
	bool	closed;
	bool	trunc;
}	t_cone;


typedef enum e_type_obj
{
	SPHERE,
	PLANE,
	CYLINDER,
	CONE,
	CUBE
}	t_type_obj;




typedef struct s_group t_group;

typedef struct s_object
{
	int			id;
	t_type_obj	type;
	union
	{
		t_sphere	s;
		t_plane		pl;
		t_cylinder	cy;
		t_cone		co;
	};
	t_material	material;
	t_mat4		trans;
	t_group			*parent;
}	t_object;

struct s_group
{
	t_mat4		trans;
	t_object	*obj;
};





typedef struct s_camera
{
	float	hsize;
	float	vsize;
	float	half_width;
	float	half_height;
	float	pixel_size;
	float	field_of_view;
	t_mat4	transform;
	// t_point	position;
	// t_point	orientation;
}	t_camera;

typedef struct s_ambient
{
	float	ratio;
	t_color	color;
}	t_ambient;

typedef struct s_world
{
	t_camera	camera;
	t_ambient	ambient;
	t_light		*lights;
	int			light_count;
	t_object	*obj;
	int			obj_count;
}	t_world;

typedef struct s_comps
{
	float		t;
	float		n1;
	float		n2;
	bool		inside;
	t_object	obj;
	t_point		point;
	t_point		over_point;
	t_vec		eyev;
	t_vec		normalv;
	t_vec		reflectv;
	t_point		under_point;
	float		shadow_intensity;
}	t_comps;

enum
{
	AMBIENT, LIGHT, CAMERA, OBJECT, COMMENT
};
/////////////////////////


// RAYS AND INTERSECT //
typedef struct s_ray
{
	t_point	origin;
	t_vec	direction;
}	t_ray;

typedef struct s_intersect
{
	int		count;
	float	points[2];
	int		object_id;
}	t_intersect;

typedef struct s_intersection
{
	float		t;
	t_object	*obj;			//	propably a * cause i think obj need to change some kind of there value
}	t_intersection;

typedef struct s_intersections
{
	t_intersection			*hit;
	struct s_intersections	*next;
	struct s_intersections	*prev;
}	t_intersections;
////////////////////////////

// MLX //
typedef struct s_mlx_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx_data;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_mlx_data	*data;
}	t_mlx;
////////////////////////////

enum {
	GLASS1, GLASS2, GLASS3,
	METAL1, METAL2, METAL3
};




# include "prototypes_miniRT.h"

#endif
