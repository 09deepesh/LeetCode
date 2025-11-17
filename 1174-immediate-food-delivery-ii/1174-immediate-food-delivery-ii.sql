# Write your MySQL query statement below
-- select round(sum(case when min(order_date) and order_by = "immediate" then 1 else 0 end ) / count(case when min(order_date)  then 1 else 0 end),2) as immediate_percentage  customer_id,

-- case when customer_pref_delivery_date = order_date then "immediate" else "scheduled" end as order_by from Delivery group by customer_id 

select round(avg(order_date = customer_pref_delivery_date ) *100 ,2) as immediate_percentage from Delivery where (order_date,customer_id) in (
    select min(order_date) , customer_id from Delivery group by customer_id
)