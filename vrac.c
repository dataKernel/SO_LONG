//creation de l'image de destination + setup w:h values
 map.width = 1400;
 map.height = 700;
 map.img = mlx_new_image(mlx, map.width, map.height);
 map.addr = mlx_get_data_addr(map.img, &map.bits_per_pixel, &map.line_length, &map.endian);
 //creation de l'image source (sprite)
 sprite.img = mlx_xpm_file_to_image(mlx, "./sprites/ground_base_1.xpm", &sprite.width, &sprite.height);
 sprite.addr = mlx_get_data_addr(sprite.img, &sprite.bits_per_pixel, &sprite.line_length, &sprite.endian);

 ft_pixel_put(&map, 0, 0, ft_pixel_get(sprite, 0, 0));
 ft_pixel_put(&map, 0, 0, ft_pixel_get(sprite, 0, 1));
 ft_pixel_put(&map, 0, 0, ft_pixel_get(sprite, 0, 2));
 ft_pixel_put(&map, 0, 0, ft_pixel_get(sprite, 0, 3));
 ft_pixel_put(&map, 0, 0, ft_pixel_get(sprite, 0, 4));
 ft_pixel_put(&map, 0, 0, ft_pixel_get(sprite, 0, 5));
 ft_pixel_put(&map, 0, 0, ft_pixel_get(sprite, 0, 6));
 ft_pixel_put(&map, 0, 0, ft_pixel_get(sprite, 0, 7));
 ft_pixel_put(&map, 0, 0, ft_pixel_get(sprite, 0, 8));
 ft_pixel_put(&map, 0, 0, ft_pixel_get(sprite, 0, 9));

mlx_put_image_to_window(mlx, window, map.img, 5, 5);
 mlx_loop(mlx);
