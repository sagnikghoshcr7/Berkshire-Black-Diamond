DROP TABLE IF EXISTS product;

CREATE TABLE product (
product_id SERIAL PRIMARY KEY NOT NULL,
name VARCHAR(40) NOT NULL,
description VARCHAR(80) NOT NULL,
price INTEGER NOT NULL,
first_image_url VARCHAR(500) NOT NULL,
second_image_url VARCHAR(500) NOT NULL
);