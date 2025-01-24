SELECT id, given_name,  surname, match, COUNT(*) AS count
FROM p_partner
GROUP BY given_name, surname, match
Having count(*) >1;