
CREATE FUNCTION LoginAdmin
    (@nom NVARCHAR(100), @password NVARCHAR(100))
RETURNS INT
AS
BEGIN
    DECLARE @adminID INT;
    SELECT @adminID = id
    FROM Admin
    WHERE nom = @nom AND password = @password;
    RETURN @adminID;
END;
