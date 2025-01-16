SELECT 
    p_partner_key, p_given_name, p_surname
FROM
    Kardia_DB.p_partner
WHERE
    (p_given_name , p_surname) IN (SELECT 
            p_given_name, p_surname
        FROM
            Kardia_DB.p_partner
		WHERE NOT p_given_name = ""
        GROUP BY p_given_name , p_surname
        HAVING COUNT(*) > 1)
ORDER BY p_given_name, p_surname;