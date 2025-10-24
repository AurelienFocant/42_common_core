#ifndef PROTOTYPES_MINIRT_H
# define PROTOTYPES_MINIRT_H

#include "miniRT.h"

/*----------------  src  ---------------*/
/* File: 0_main.c */
void	print_progress(float y, float max);
void	render(t_camera c, t_world *w, t_mlx_data *m_data);
void	render_with_mlx(t_world *w);


/*----------------  src/1_parsing  ---------------*/
/* File: 0_parse_argfile.c */
t_world	parse_argfile(char *filename);


/*----------------  src/1_parsing/1_count_and_check  ---------------*/
/* File: 0_check_count.c */
int	check_object(char *line, int fd);
void	check_line_by_line(t_world *w, int fd);
void	check_file_and_count(char *filename, t_world *w);

/* File: 1_check_light_cam.c */
int	check_light(char *line, int fd);
void	check_camera(char *line, int fd);
void	check_ambient(char *line, int fd);

/* File: 2_check_objects.c */
int	check_sp(char *line, int fd);
int	check_pl(char *line, int fd);
int	check_cy(char *line, int fd);
int	check_co(char *line, int fd);
int	check_cu(char *line, int fd);

/* File: 8_checking_utils.c */
float	expect_float(float minmax[2], char **words, char *line, int fd);
void	expect_single_float(float minmax[2], char **words, char *line, int fd);
void	expect_vector(float minmax[2], char **words, char *line, int fd);
void	expect_whitespace(char **words, char *line, int fd);
void	expect_comma(char **words, char *line, int fd);

/* File: 9_checking_utils2.c */
void	expect_bool(char **words, char *line, int fd);
void	expect_end(char **words, char *line, int fd);
bool	is_just_whitespace(char *line);


/*----------------  src/1_parsing/2_parse_and_alloc  ---------------*/
/* File: 0_parse_world.c */
t_object	parse_obj(char *line);
void	fill_world(int fd, t_world *w);
void	parse_world(char *filename, t_world *w);

/* File: 1_parse_light_cam.c */
void	area_light(t_light *light, t_vec v1, t_vec v2, t_pair uv);
t_light	build_spot_light(t_light l, char **line);
t_light	parse_light(char *line);
t_ambient	parse_ambient(char *line);
t_camera	parse_camera(char *line);


/*----------------  src/1_parsing/2_parse_and_alloc/2_parse_objects  ---------------*/
/* File: 2_parse_objects.c */
t_object	parse_sp(char *line);
t_object	parse_pl(char *line);
t_object	parse_cu(char *line);

/* File: 3_parse_obj_cy_co.c */
t_object	parse_cy(char *line);
t_object	parse_co(char *line);


/*----------------  src/1_parsing/2_parse_and_alloc/3_parse_optionals  ---------------*/
/* File: 0_parse_optionals.c */
bool	has_material(char *s);
bool	has_pattern(char *s);
bool	has_texture(char *s);
bool	has_rotation(char *s);
t_object	parse_optionals(t_object o, char **line);

/* File: 1_parse_rotation.c */
int	which_axes(char **line);
t_mat4	find_and_do_rotation(int which, float radians);
void	parse_rotation(t_object *o, char **line);

/* File: 2_parse_patterns.c */
void	get_pattern_type(t_object *o, char **line);
void	parse_simple_pattern(t_object *o, char **line);
void	parse_uv_pattern(t_object *o, char **line);
void	parse_pattern(t_object *o, char **line);

/* File: 3_parse_materials.c */
int	get_material_type(char **line);
void	parse_mat(int type, t_object *o);
void	parse_material(t_object *o, char **line);

/* File: 4_parse_textures.c */
size_t	len_tex(char *line);
char	*get_next_filename(char **line);
char	*get_texture_path(char **line);
char	*get_cube_textures_dir(char **line);
void	parse_texture(t_object *o, char **line);

/* File: 5_parse_scale_tex.c */
bool	has_scale_tex(char *s);
void	parse_scale_tex(t_object *o, char **line);


/*----------------  src/1_parsing/2_parse_and_alloc  ---------------*/
/* File: 9_parsing_utils.c */
void	adv_next_word(char **s);
void	consume_comma(char **s);
t_vec	get_next_vector(char **s);
float	get_next_float(char **s);
t_color	get_next_color(char **line);


/*----------------  src/1_parsing/3_parsing_utils  ---------------*/
/* File: 0_utils.c */
void	consume_paren(char **line);
int	len(char *s);
bool	match(char *s, char *target);
int	first_word(char *s);
int	object_kind(char *s);

/* File: 1_rot_matrix_Rodrigues_formula.c */
bool	is_vec_zero(t_vec v);
t_mat4	rodrigues_formula(t_vec axis, float angle);
t_mat4	rotation_matrix_Rodrigues_formula(t_vec target_normalv);


/*----------------  src/2_objects  ---------------*/
/* File: 0_create_objects.c */
t_object	create_object(t_type_obj type);


/*----------------  src/2_objects/1_materials  ---------------*/
/* File: 0_material.c */
t_pattern	empty_pattern(void);
t_material	default_material(void);


/*----------------  src/2_objects/1_materials/1_glass  ---------------*/
/* File: glass1_material.c */
void	glass1_object(t_object *o);
void	glass2_object(t_object *o);
void	glass3_object(t_object *o);


/*----------------  src/2_objects/1_materials/2_metal  ---------------*/
/* File: metal1_material.c */


/*----------------  src/2_objects/2_patterns  ---------------*/
/* File: patterns.c */
t_color	pattern_at_object(t_pattern *pat, t_object *o, t_point world_space);


/*----------------  src/2_objects/2_patterns/simple_patterns  ---------------*/
/* File: simple_patterns1.c */
t_color	checker_at(t_simple_pattern *pat, t_point p);
t_color	texture_map(t_uv_pattern *pat, t_object *o, t_point p);
t_color	simple_pat(t_simple_pattern *pat, t_point pattern_space);

/* File: simple_patterns2.c */
t_color	stripe_at(t_simple_pattern *pat, t_point p);
t_color	gradient_at(t_simple_pattern *pat, t_point p);
t_color	ring_at(t_simple_pattern *pat, t_point p);


/*----------------  src/2_objects/2_patterns/uv_patterns/cube_mapping  ---------------*/
/* File: cube_mapping1.c */
t_pair	cube_uv_up(t_point p);
t_pair	cube_uv_down(t_point p);
t_pair	cube_map(t_point p, int face);

/* File: cube_mapping2.c */
t_pair	cube_uv_front(t_point p);
t_pair	cube_uv_back(t_point p);
t_pair	cube_uv_left(t_point p);
t_pair	cube_uv_right(t_point p);


/*----------------  src/2_objects/2_patterns/uv_patterns  ---------------*/
/* File: map.c */
t_pair	spherical_map(t_point p);
t_pair	planar_map(t_point p);
t_pair	cylindrical_map(t_point p);
int	face_form_point(t_point p);

/* File: uv_patterns.c */
t_color	cube_colors(t_uv_pattern *ck, float u, float v);
t_color	cube_textures(t_uv_pattern *ck, float u, float v);
t_color	mapped_checkers(t_uv_pattern *uv_pat, float u, float v);
t_color	texture(t_uv_pattern *uv_pat, float u, float v);
t_color	uv_pattern_at(t_uv_pattern *uv_pat, float u, float v);


/*----------------  src/2_objects/3_textures  ---------------*/
/* File: mlx_textures.c */
bool	create_tex(t_mlx *mlx, char *path, t_texture *tex);
char	*create_cube_texture_path(t_object *o, int f);
void	activate_simple_texture(t_object *o, t_mlx *mlx);
void	activate_cube_texture(t_object *o, t_mlx *mlx);
void	activate_textures(t_world *w, t_mlx *mlx);


/*----------------  src/3_ray_tracing/calc_colors  ---------------*/
/* File: area_light.c */
t_point	point_on_light(t_light light, int u, int v);
float	intensity_at(t_world *w, t_point point, int which_light);
bool	is_in_shadow(t_world *w, t_point p, t_point light_position);

/* File: color_at.c */
t_color	intensity_per_sample(t_light *light, t_color sum, t_comps *comps);
t_color	surface_lighting(t_world *w, t_comps *comps, int which_light);
t_color	shade_hit(t_world *w, t_comps *comps, int which_light, int remaining_recurse);
t_comps	prepare_computations(t_intersection *hit, t_ray r, t_intersections *xs);
t_color	color_at(t_world *w, t_ray r, int remaining_recurse);

/* File: phong_model.c */
t_color	get_ambient(t_world *w, t_comps *comps, t_color obj_color);
void	add_specular(t_light light, t_comps *comps, t_vec lightv, t_color *sum);
void	add_diffuse(t_light light, t_comps *comps, float light_dot_normal, t_color *sum);
void	add_diffuse_specular(t_light light, t_comps *comps, t_pair uv, t_color *sum);
t_color	color_if_pattern(t_comps *comps);


/*----------------  src/3_ray_tracing/calc_colors/reflect_refract  ---------------*/
/* File: fresnel_effect.c */
float	schlick(t_comps *comps);

/* File: reflection_refraction.c */
t_color	reflected_lighting(t_world *w, t_comps *comps, int remaining_recurse);
t_ray	compute_refract_ray(float n_ratio, float cos_i, float cos_t, t_comps *comps);
t_color	refracted_lighting(t_world *w, t_comps *comps, float remaining);

/* File: refractive_index.c */
t_intersections	*last_containers(t_intersections *containers);
void	is_hit_in_containers(t_intersections **containers, t_intersection *hit);
void	refractive_n2_index(t_comps *comps, t_intersections *containers, t_intersections *last_c);
void	prepare_refractive_index(t_comps *comps, t_intersection *hit, t_intersections *xs);


/*----------------  src/3_ray_tracing  ---------------*/
/* File: camera.c */
t_camera	camera(float hsize, float vsize, float field_of_view);
float	calc_world_pixel(int point, float pixel_size, float border);
t_ray	ray_to_world_pixel(t_camera c, int x, int y);
int	vec_to_hex_color(t_color color);


/*----------------  src/3_ray_tracing/intersections  ---------------*/
/* File: 0_intersect_world.c */
t_intersection	*hit(t_intersections *xs);
t_intersection	*intersection(float t, t_object *obj);
void	intersections(t_intersections **track, t_intersection *inter);
t_intersections	*intersect_world(t_world *w, t_ray r);

/* File: 1_intersect_objects.c */
t_intersect	empty_intersect(int object_id);
t_intersect	intersect_sp(t_object o, t_ray r);
t_intersect	intersect_pl(t_object o, t_ray r);
t_intersect	intersect_object(t_object o, t_ray r);

/* File: 2_intersect_cylinders.c */
bool	check_cap(t_ray r, float t);
t_intersect	intersect_caps(t_object o, t_ray r, t_intersect x);
t_intersect	intersect_cylinder_limits(t_object o, t_ray r, float t, t_intersect x);
t_intersect	intersect_cylinder(t_object o, t_ray r, t_discriminant disc, t_intersect x);
t_intersect	intersect_cy(t_object o, t_ray r);

/* File: 3_intersect_cones.c */
bool	check_cone_cap(float radius, t_ray r, float t);
t_intersect	intersect_cone_caps(t_object o, t_ray r, t_intersect x);
t_intersect	intersect_cone_limits(t_object o, t_ray r, float t, t_intersect x);
t_intersect	intersect_cone(t_object o, t_ray r, t_discriminant disc, t_intersect x);
t_intersect	intersect_co(t_object o, t_ray r);

/* File: 4_intersect_cubes.c */
t_pair	check_axis(float origin, float direction);
float	min(float v1, float v2, float v3);
float	max(float v1, float v2, float v3);
t_intersect	intersect_cu(t_object o, t_ray r);

/* File: 5_intersection_utils.c */
void	is_intersections_sorted(bool *sorted, t_intersections *node);
void	sort_intersections(t_intersections **xs);
void	add_intersections(t_object *o, t_ray r, t_intersections **xs);


/*----------------  src/3_ray_tracing/normal_vectors  ---------------*/
/* File: normals.c */
t_vec	normal_at_s(t_point p);
t_vec	normal_at_pl(void);
t_vec	normal_at_cu(t_point p);
t_vec	normal_at(t_object o, t_point world_point);

/* File: normals2.c */
t_vec	normal_at_cy(t_object o, t_point p);
t_vec	normal_at_co(t_object o, t_point p);


/*----------------  src/3_ray_tracing  ---------------*/
/* File: rays.c */
t_ray	ray(t_point origin, t_vec direction);
t_point	position(t_ray ray, float t);
t_ray	transform_r(t_ray r, t_mat4 m);
t_vec	reflect(t_vec in, t_vec normal);


/*----------------  src/4_group  ---------------*/
/* File: group.c */


/*----------------  src/8_math/matrices/inversions  ---------------*/
/* File: inv_utils_mat3.c */
float	determinant_mat3(t_mat3 m);

/* File: inv_utils_mat4.c */
float	cofactor_mat4(t_mat4 m, int row, int col);
float	determinant_mat4(t_mat4 m);

/* File: inversion.c */
t_mat4	creat_zeroed_mat4(void);
t_mat4	inverse_mat4(t_mat4 m);


/*----------------  src/8_math/matrices  ---------------*/
/* File: matrices.c */
t_mat4	multi_mat4(t_mat4 m1, t_mat4 m2);
t_tuple	multi_mat4_tuple(t_mat4 m, t_tuple t);
t_mat4	creat_identity_matrix(void);
t_mat4	transpose_mat4(t_mat4 m);


/*----------------  src/8_math/matrices/transformations  ---------------*/
/* File: rotations.c */
t_mat4	rotation_x(float rad);
t_mat4	rotation_y(float rad);
t_mat4	rotation_z(float rad);

/* File: transformations.c */
t_mat4	translation(float x, float y, float z);
t_mat4	scaling(float x, float y, float z);
t_mat4	shearing(float sh[6]);


/*----------------  src/8_math/matrices  ---------------*/
/* File: view_transformation.c */
t_mat4	view_transform(t_point from, t_point to, t_vec up);


/*----------------  src/8_math/tuples  ---------------*/
/* File: color.c */
t_tuple	add_colors(t_tuple c1, t_tuple c2);
t_tuple	sub_colors(t_tuple c1, t_tuple c2);
t_tuple	scalar_multi_color(float scalar, t_tuple c);
t_tuple	blend_colors(t_tuple c1, t_tuple c2);

/* File: complex_tuple_operation.c */
float	magnitude(t_tuple vec);
t_tuple	normalize_tuple(t_tuple vec);
float	dot_product(t_tuple a, t_tuple b);
t_tuple	cross_product(t_tuple va, t_tuple vb);
t_tuple	scalar_div_tuple(float scalar, t_tuple a);

/* File: operation_tuple.c */
t_tuple	add_tuple(t_tuple a, t_tuple b);
t_tuple	sub_tuple(t_tuple a, t_tuple b);
t_tuple	negatif_tuple(t_tuple a);
t_tuple	multi_tuple(t_tuple a, t_tuple b);
t_tuple	scalar_multi_tuple(float scalar, t_tuple a);

/* File: tuple.c */
t_tuple	creat_tuple(float x, float y, float z, float w);
t_tuple	point(float x, float y, float z);
t_tuple	vector(float x, float y, float z);
void	print_tuple(t_tuple t);
t_tuple	color(float red, float green, float blue);


/*----------------  src/9_utils  ---------------*/
/* File: error_exit.c */
void	error_exit(char *s);
void	file_error_exit(char *line, int fd);
void	failed_texture_msg(t_object *o);

/* File: floats.c */
bool	is_float_equal(float a, float b, float epsilon);
void	swapf(float *a, float *b);

/* File: free.c */
void	ft_free_tex_face(t_texture *tex, t_mlx *mlx);
void	ft_free_tex_world(t_world *w, t_mlx *mlx);
void	ft_free_intersections(t_intersections *xs, bool is_containers);


/*----------------  src/9_utils/mlx  ---------------*/
/* File: mlx_hook.c */
int	out_prog(t_mlx *interface);
void	events_init(t_mlx *interface);

/* File: mlx_init.c */
void	multiple_pixel_put(t_mlx_data *data, int x, int y, int color);
t_color	get_pixel(t_texture *tex, int x, int y);
void	my_mlx_pixel_put(t_mlx_data *data, int x, int y, int color);


/*----------------  src/9_utils  ---------------*/
/* File: random_num.c */
float	sequence(float *tab, int *tab_pos, int tab_size);
float	calc_jitter(void);

#endif
