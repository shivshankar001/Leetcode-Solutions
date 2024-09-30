SELECT r.contest_id, ROUND((COUNT(r.contest_id) * 100 / (SELECT COUNT(*) FROM Users)), 2) AS percentage
FROM Register AS r
LEFT JOIN Users AS u
ON r.user_id = u.user_id
GROUP BY r.contest_id
ORDER BY percentage DESC, r.contest_id ASC;
