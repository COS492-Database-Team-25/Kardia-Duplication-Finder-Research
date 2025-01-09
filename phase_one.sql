select id, given_name, surname
from p_partner

where (given_name, surname) in
(select given_name, surname
from p_partner
group by given_name, surname
having count(*) > 1)

order by given_name;