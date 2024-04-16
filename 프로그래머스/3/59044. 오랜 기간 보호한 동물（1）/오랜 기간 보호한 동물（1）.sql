
(
SELECT i.NAME, i.DATETIME
from ANIMAL_INS as i left outer join ANIMAL_OUTS as o on i.ANIMAL_ID = o.ANIMAL_ID
where o.ANIMAL_ID is NULL
    order by i.DATETIME
    limit 3
)