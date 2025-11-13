--Lab 5
--Q1
SELECT DISTINCT category_name
FROM categories_mgs
WHERE category_id IN (
    SELECT category_id
    FROM products_mgs
)
ORDER BY category_name;

--Q2
SELECT
    product_name,
    list_price
FROM products_mgs
WHERE list_price > (
    SELECT AVG(list_price)
    FROM products_mgs
)
ORDER BY list_price DESC;

--Q3
SELECT category_name
FROM categories_mgs c
WHERE NOT EXISTS (
    SELECT 1
    FROM products_mgs p
    WHERE p.category_id = c.category_id
);

--Q4
SELECT 
    email_address,
    MAX(order_total) AS max_order_total
FROM (
    SELECT 
        (SELECT email_address 
         FROM customers_mgs c 
         WHERE c.customer_id = o.customer_id) AS email_address,
        o.order_id,
        (SELECT SUM((oi.item_price - oi.discount_amount) * oi.quantity)
         FROM order_items_mgs oi 
         WHERE oi.order_id = o.order_id) AS order_total
    FROM orders_mgs o
    GROUP BY o.order_id, o.customer_id
) order_summary
GROUP BY email_address;

--Q5
SELECT 
    product_name,
    discount_percent
FROM products_mgs
WHERE discount_percent IN (
    SELECT discount_percent
    FROM products_mgs
    GROUP BY discount_percent
    HAVING COUNT(*) = 1
)
ORDER BY product_name;

--Q6
SELECT 
    c.email_address,
    o.order_id,
    o.order_date
FROM orders_mgs o
JOIN customers_mgs c
    ON o.customer_id = c.customer_id
WHERE o.order_date = (
    SELECT MIN(o2.order_date)
    FROM orders_mgs o2
    WHERE o2.customer_id = o.customer_id
);
