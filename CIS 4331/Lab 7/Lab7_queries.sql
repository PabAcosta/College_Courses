--Lab 7
--Q1
CREATE INDEX index_order_date
ON Orders_mgs(order_date);

--Q2
DROP SEQUENCE seq_user_id;
DROP SEQUENCE seq_download_id;
DROP SEQUENCE seq_product_id;

CREATE SEQUENCE seq_user_id;
CREATE SEQUENCE seq_download_id;
CREATE SEQUENCE seq_product_id;

DROP TABLE Downloads_ex;
DROP TABLE Users_ex;
DROP TABLE Products_ex;

CREATE TABLE Users_ex (
    user_id       NUMBER PRIMARY KEY,
    email_address VARCHAR2(255 BYTE) UNIQUE,
    first_name    VARCHAR2(60 BYTE) NOT NULL,
    last_name     VARCHAR2(60 BYTE) NOT NULL
);

CREATE TABLE Products_ex (
    product_id    NUMBER PRIMARY KEY,
    product_name  VARCHAR2(255 BYTE) UNIQUE
);

CREATE TABLE Downloads_ex (
    download_id   NUMBER PRIMARY KEY,
    user_id       NUMBER NOT NULL,
    download_date DATE NOT NULL,
    filename      VARCHAR2(200 BYTE) NOT NULL,
    product_id    NUMBER NOT NULL,
    FOREIGN KEY (user_id) REFERENCES Users_ex(user_id),
    FOREIGN KEY (product_id) REFERENCES Products_ex(product_id)
);

--Q3
INSERT INTO Users_ex (user_id, email_address, first_name, last_name)
VALUES (1, 'johnsmith@gmail.com', 'John', 'Smith');

INSERT INTO Users_ex (user_id, email_address, first_name, last_name)
VALUES (2, 'janedoe@yahoo.com', 'Jane', 'Doe');

INSERT INTO Products_ex (product_id, product_name)
VALUES (1, 'Local Music Vol 1');

INSERT INTO Products_ex (product_id, product_name)
VALUES (2, 'Local Music Vol 2');

INSERT INTO Downloads_ex (download_id, user_id, download_date, filename, product_id)
VALUES (1, 1, SYSDATE, 'pedals_are_falling.mpd', 2);

INSERT INTO Downloads_ex (download_id, user_id, download_date, filename, product_id)
VALUES (2, 2, SYSDATE, 'turn_signal.mp3', 1);

INSERT INTO Downloads_ex (download_id, user_id, download_date, filename, product_id)
VALUES (3, 2, SYSDATE, 'one_horse_town.mpd', 2);

--Q4
ALTER TABLE Products_ex
ADD price NUMBER(5,2) DEFAULT 9.99;

ALTER TABLE Products_ex
ADD date_added DATE;

--Q5
ALTER TABLE Users_ex
MODIFY first_name VARCHAR2(20) NULL;

UPDATE Users_ex
SET first_name = NULL
WHERE user_id = 1;

UPDATE Users_ex
SET first_name = 'fake_firstname_1234567890'
WHERE user_id = 2;