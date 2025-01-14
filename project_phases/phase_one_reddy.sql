SELECT 
    p_partner_key as id, p_given_name as given_name, p_surname as surname 
FROM
    Kardia_DB.p_partner,
WHERE
    (p_given_name , p_surname) IN (SELECT 
            p_given_name as given_name, p_surname as surname
        FROM
            Kardia_DB.p_partner
		WHERE NOT p_given_name = ""
        GROUP BY given_name , surname
        HAVING COUNT(*) > 1)
ORDER BY given_name, surname;