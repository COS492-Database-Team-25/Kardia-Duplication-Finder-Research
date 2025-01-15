SELECT 
    p_partner_key as id, p_contact_data as contact_data, p_phone_area_city as phone_area_city
FROM
    Kardia_DB.p_contact_info
WHERE
    (p_contact_data , p_phone_area_city) IN (SELECT 
            p_contact_data as contact_data, p_phone_area_city as phone_area_city
        FROM
            Kardia_DB.p_contact_info
		WHERE NOT p_contact_data = ""
        GROUP BY contact_data , phone_area_city
        HAVING COUNT(*) > 1)
ORDER BY contact_data, phone_area_city;