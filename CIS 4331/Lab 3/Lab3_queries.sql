--Lab 3
--Q1
SELECT category_name, product_name, list_price
FROM categories_mgs 
INNER JOIN products_mgs 
    ON categories_mgs.category_id = products_mgs.category_id
ORDER BY category_name ASC, product_name ASC;

--Q2
SELECT first_name, last_name, line1, city, state, zip_code
FROM customers_mgs
INNER JOIN addresses_mgs
    ON customers_mgs.customer_id = addresses_mgs.customer_id
WHERE customers_mgs.email_address = 'allan.sherwood@yahoo.com';

--Q3
SELECT first_name, last_name, line1, city, state, zip_code
FROM customers_mgs
INNER JOIN addresses_mgs
    ON customers_mgs.shipping_address_id = addresses_mgs.address_id;

--Q4
SELECT last_name, first_name, order_date, product_name, item_price,
    discount_amount, quantity
FROM customers_mgs c
INNER JOIN orders_mgs o
    ON c.customer_id = o.customer_id
INNER JOIN order_items_mgs oi
    ON o.order_id = oi.order_id
INNER JOIN products_mgs p
    ON oi.product_id = p.product_id
ORDER BY last_name ASC, order_date ASC, product_name ASC;

--Q5
SELECT p1.product_name, p1.list_price
FROM products_mgs p1
INNER JOIN products_mgs p2
    ON p1.list_price = p2.list_price
    AND p1.product_id <> p2.product_id
ORDER BY p1.product_name ASC;

--Q6
SELECT c.category_name, p.product_id
FROM categories_mgs c
LEFT JOIN products_mgs p
    ON c.category_id = p.category_id
WHERE p.product_id IS NULL;

--Q7
SELECT 'SHIPPED' AS ship_status, order_id, order_date
FROM orders_mgs
WHERE ship_date IS NOT NULL

UNION

SELECT 'NOT SHIPPED' AS ship_status, order_id, order_date
FROM orders_mgs
WHERE ship_date IS NULL

ORDER BY order_date ASC;