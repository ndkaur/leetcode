-- # Write your MySQL query statement below
-- # so main thing to do here is get all the names of products in one col
select sell_date, 
count(distinct(product)) as num_sold,
group_concat(distinct product order by product asc separator ',') as products
from activities 
group by sell_date
order by sell_date asc;