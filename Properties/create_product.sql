INSERT INTO product (name, description, price, first_image_url, second_image_url)
VALUES ($1, $2, $3, $4, $5);
SELECT * FROM product
ORDER BY product_id ASC;