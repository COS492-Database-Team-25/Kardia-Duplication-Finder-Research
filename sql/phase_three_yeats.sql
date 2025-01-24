SELECT 
    p_partner.p_partner_key as p_id, p_given_name as given_name, p_surname as surname, p_address_1 as address, p_address_2 as backup_address
FROM
    Kardia_DB.p_partner INNER JOIN Kardia_DB.p_location
ON
	p_partner.p_partner_key = p_location.p_partner_key
WHERE
    (p_given_name , p_surname, p_address_1, p_address_2) IN (SELECT 
            p_given_name as given_name, p_surname as surname, p_address_1 as address, p_address_2 as backup_address
        FROM
            Kardia_DB.p_partner INNER JOIN Kardia_DB.p_location
		ON
			p_partner.p_partner_key = p_location.p_partner_key
		WHERE NOT p_given_name = "" OR NOT p_address_1 = ""
        GROUP BY given_name , surname, address
        HAVING COUNT(*) > 1)
ORDER BY given_name, surname, address;