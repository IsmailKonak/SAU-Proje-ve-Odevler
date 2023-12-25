-- Drop procedures
DROP PROCEDURE IF EXISTS "DeleteMyAccount"(IN TEXT, IN TEXT);
DROP PROCEDURE IF EXISTS "ChangePassword"(IN TEXT, IN TEXT);
DROP PROCEDURE IF EXISTS "SignUp"(IN TEXT, IN TEXT, IN TEXT);
DROP PROCEDURE IF EXISTS "AdditionalUserInfoPHS"(IN INT, IN TEXT, IN VARCHAR(75), IN INT);
DROP PROCEDURE IF EXISTS "AdditionalUserInfoCS"(IN INT, IN VARCHAR(75), IN VARCHAR(75), IN INT);
DROP PROCEDURE IF EXISTS "AddAddressInfo"(IN INT, IN TEXT, IN TEXT, IN TEXT, IN TEXT);

/* STORED PROCEDURES*/

CREATE OR REPLACE PROCEDURE "DeleteMyAccount"(IN user_email TEXT, IN user_password__ TEXT)
LANGUAGE plpgsql AS $$
DECLARE
	user_id__ INT;
BEGIN
	-- Fetch user_id based on the input email and password
	SELECT "user_id" INTO user_id__
	FROM "User"
	WHERE "Email" = user_email AND "User"."user_password" = user_password__;

	-- Check if the user exists
	IF user_id__ IS NOT NULL THEN
		-- Delete the user
		DELETE FROM "User"
		WHERE "user_id" = user_id__;
	ELSE
		RAISE EXCEPTION 'User not found for email: %', user_email;
	END IF;
END;
$$;

CREATE OR REPLACE PROCEDURE "ChangePassword"(IN user_email TEXT, IN new_password TEXT)
LANGUAGE plpgsql AS $$
BEGIN
	-- Update the user password
	UPDATE "User"
	SET "user_password" = new_password
	WHERE "Email" = user_email;

	-- Check if the user exists
	IF NOT FOUND THEN
		RAISE EXCEPTION 'User not found for email: %', user_email;
	END IF;
END;
$$;


CREATE OR REPLACE PROCEDURE "SignUp"(IN username TEXT,IN user_email TEXT, IN user_password__ TEXT)
LANGUAGE plpgsql AS $$
BEGIN
		INSERT INTO "User"("Username", "Email", "user_password", "RegistrationDate")
		VALUES(username, user_email, user_password__, CURRENT_DATE);
END;
$$;


CREATE OR REPLACE PROCEDURE "AdditionalUserInfoPHS"(IN user_id__ INT, IN user_type__ TEXT, IN school_name__ VARCHAR(75), IN grade__ INT)
LANGUAGE plpgsql AS $$
BEGIN
	IF user_type__ = 'PSS' THEN
		UPDATE "User"
		SET "UserType" = 'PSS'
		WHERE "user_id" = user_id__;

		INSERT INTO "PrimarySchoolStudent"("primarySchoolStudent_id", "PrimarySchoolName", "Grade")
		VALUES(user_id__, school_name__, grade__);
	
	ELSEIF user_type__ = 'HSS' THEN
		UPDATE "User"
		SET "UserType" = 'HSS'
		WHERE "user_id" = user_id__;

		INSERT INTO "HighSchoolStudent"("highSchoolStudent_id", "HighSchoolName", "Grade")
		VALUES(user_id__, school_name__, grade__);

	END IF;
END;
$$;


CREATE OR REPLACE PROCEDURE "AdditionalUserInfoCS"(IN user_id__ INT, IN college_name__ VARCHAR(75), IN bachelor_type__ VARCHAR(75), IN grade__ INT)
LANGUAGE plpgsql AS $$
BEGIN
	UPDATE "User"
	SET "UserType" = 'CSS'
	WHERE "user_id" = user_id__;

	INSERT INTO "CollegeStudent"("collegeStudent_id", "CollegeName", "BachelorType", "Grade")
	VALUES(user_id__, college_name__, bachelor_type__, grade__);
END;
$$;

CREATE OR REPLACE PROCEDURE "AddAddressInfo"(IN user_id__ INT, IN street__ TEXT, IN neighborhood__ TEXT, IN city__ TEXT, IN country__ 	TEXT)
LANGUAGE plpgsql AS $$
DECLARE
	street_id__ INT;
	neighborhood_id__ INT;
	city_id__ INT;
	country_id__ INT;
	address_id__ INT;
BEGIN
	INSERT INTO "Street"("StreetName") VALUES(street__);
	INSERT INTO "Neighborhood"("NeighborhoodName") VALUES(neighborhood__);
	INSERT INTO "City"("CityName") VALUES(city__);
	INSERT INTO "Country"("CountryName") VALUES(country__);

	SELECT "street_id" INTO street_id__ FROM "Street" WHERE "StreetName" = street__;
	SELECT "neighborhood_id" INTO neighborhood_id__ FROM "Neighborhood" WHERE "NeighborhoodName" = neighborhood__;
	SELECT "CityId" INTO city_id__ FROM "City" WHERE "CityName" = city__;
	SELECT "CountryId" INTO country_id__ FROM "Country" WHERE "CountryName" = country__;

	INSERT INTO "Address"("City", "Country", "Neighborhood", "Street")
	VALUES(city_id__, country_id__, neighborhood_id__, street_id__);

	SELECT "address_id" INTO address_id__ FROM "Address" 
	WHERE "City" = city_id__ AND "Country" = country_id__ AND "Neighborhood" = neighborhood_id__ AND "Street" = street_id__;

	UPDATE "User"
	SET "Address" = address_id__
	WHERE "user_id" = user_id__;
END;
$$;