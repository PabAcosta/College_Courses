--Lab 4
--Q1
SELECT 
    COUNT(order_id) AS order_count, 
    SUM(tax_amount) AS tax_total
FROM orders_mgs;

--Q2
SELECT
    c.category_name,
    COUNT(p.product_id) AS product_count,
    MAX(p.list_price) AS most_expensive_product
FROM categories_mgs c 
INNER JOIN products_mgs p
    ON c.category_id = p.category_id
GROUP BY c.category_name
ORDER BY product_count DESC;

--Q3
SELECT 
    c.email_address,
    SUM(oi.item_price * oi.quantity) AS item_price_total,
    SUM(oi.discount_amount * oi.quantity) AS discount_amount_total
FROM customers_mgs c
INNER JOIN orders_mgs o
    ON c.customer_id = o.customer_id
INNER JOIN order_items_mgs oi
    ON o.order_id = oi.order_id
GROUP BY c.email_address
ORDER BY item_price_total DESC;

--Q4
SELECT
    c.email_address,
    COUNT(o.order_id) AS order_count,
    SUM((oi.item_price - oi.discount_amount) * oi.quantity) AS order_total
FROM customers_mgs c
INNER JOIN orders_mgs o
    ON c.customer_id = o.customer_id
INNER JOIN order_items_mgs oi
    ON o.order_id = oi.order_id
GROUP BY c.email_address
HAVING COUNT(o.order_id) > 1
ORDER BY order_total DESC;

--Q5
SELECT
    c.email_address,
    COUNT(o.order_id) AS order_count,
    SUM((oi.item_price - oi.discount_amount) * oi.quantity) AS order_total
FROM customers_mgs c
INNER JOIN orders_mgs o
    ON c.customer_id = o.customer_id
INNER JOIN order_items_mgs oi
    ON o.order_id = oi.order_id
WHERE oi.item_price > 400
GROUP BY c.email_address
HAVING COUNT(o.order_id) > 1
ORDER BY order_total DESC;

--Q6
SELECT 
    p.product_name,
    SUM((oi.item_price - oi.discount_amount) * oi.quantity) AS product_total
FROM products_mgs p
INNER JOIN order_items_mgs oi
    ON p.product_id = oi.product_id
GROUP BY ROLLUP(p.product_name);

--Q7
SELECT 
    c.email_address,
    COUNT(DISTINCT oi.product_id) AS number_of_products
FROM customers_mgs c
INNER JOIN orders_mgs o
    ON c.customer_id = o.customer_id
INNER JOIN order_items_mgs oi
    ON o.order_id = oi.order_id
GROUP BY c.email_address
HAVING COUNT(DISTINCT oi.product_id) > 1
ORDER BY c.email_address ASC;

--Q8
SELECT
    CASE 
        WHEN GROUPING(c.category_name) = 1 THEN '========'
        ELSE c.category_name
    END AS category_name,
    CASE 
        WHEN GROUPING(p.product_name) = 1 THEN '========'
        ELSE p.product_name
    END AS product_name,
    SUM(oi.quantity) AS QTY_PURCHASED
FROM categories_mgs c
INNER JOIN products_mgs p
    ON c.category_id = p.category_id
INNER JOIN order_items_mgs oi
    ON p.product_id = oi.product_id
GROUP BY ROLLUP(c.category_name, p.product_name);

--Q9
SELECT
    order_id,
    (item_price - discount_amount) * quantity AS item_amount,
    SUM((item_price - discount_amount) * quantity) OVER (PARTITION BY order_id) AS order_amount
FROM order_items_mgs oi
ORDER BY order_id ASC;
