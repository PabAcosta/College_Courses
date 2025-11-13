--Lab 6
--Q1
INSERT INTO categories_mgs (category_id, category_name)
VALUES (5, 'Brass');

COMMIT;

--Q2
UPDATE categories_mgs
SET category_name = 'Woodwinds'
WHERE category_id = 5;

--Q3
DELETE FROM categories_mgs
WHERE category_id = 5;

--Q4
INSERT INTO products_mgs (product_id, category_id, product_code, 
    product_name, description, list_price, date_added)
VALUES (11, 4, 'dgx_640', 'Yamaha DGX 640 88-Key Digital Piano', 
    'Long description to come.', 799.99, SYSDATE);

--Q5
UPDATE products_mgs
SET discount_percent = 35
WHERE product_code = 'dgx_640';

--Q6
--Select Statement
SELECT category_id
FROM categories_mgs
WHERE category_name = 'Keyboards';

--Delete 1 with Select in it
DELETE FROM products_mgs
WHERE category_id = (
    SELECT category_id
    FROM categories_mgs
    WHERE category_name = 'Keyboards'
);

--Delete 2
DELETE FROM categories_mgs
WHERE category_name = 'Keyboards';

--Q7
INSERT INTO customers_mgs (customer_id, email_address, password,
    first_name, last_name)
VALUES (9, 'rick@raven.com', 'sesame', 'Rick', 'Raven');

--Q8
UPDATE customers_mgs
SET password = 'secret'
WHERE email_address = 'rick@raven.com';

--Q9
UPDATE customers_mgs
SET password = 'reset';

--Q10
ROLLBACK;
