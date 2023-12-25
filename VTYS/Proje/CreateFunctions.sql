-- Drop functions
DROP FUNCTION IF EXISTS calculate_full_address() CASCADE;
DROP FUNCTION IF EXISTS calculate_score_percentage() CASCADE;
DROP FUNCTION IF EXISTS increase_topic_content_num() CASCADE;
DROP FUNCTION IF EXISTS increase_subject_topic_content_num() CASCADE;
DROP FUNCTION IF EXISTS "GetUserSchoolInfo"(IN INT, IN TEXT) CASCADE;
DROP FUNCTION IF EXISTS "AuthenticateUser"(IN TEXT, IN TEXT) CASCADE;
DROP FUNCTION IF EXISTS "GetQuestionAndAnswer"(IN INT) CASCADE;
DROP FUNCTION IF EXISTS "ConcatenateSubjects"() CASCADE;
DROP FUNCTION IF EXISTS "GetSubjectDescription"(IN VARCHAR(150)) CASCADE;


/*	FONKSIYONLAR	*/

CREATE OR REPLACE FUNCTION "GetUserSchoolInfo"(IN user_id__ INT,IN info_type TEXT)
RETURNS TEXT AS $$
DECLARE 
	user_type__ TEXT;
	school_name__ TEXT;
	bachelor_type__ TEXT;
	grade__ INT;
	result TEXT;
BEGIN
	-- Initialize result to an empty string
	result := '';

	-- Fetch user type
	SELECT "UserType" INTO user_type__
	FROM "User"
	WHERE "user_id" = user_id__;

	-- Check if the user exists
	IF user_type__ IS NOT NULL THEN
		-- Fetch school name and grade
		IF user_type__ = 'PSS' THEN
			IF info_type = 'school_name' THEN
				SELECT "PrimarySchoolName" INTO school_name__
				FROM "PrimarySchoolStudent"
				WHERE "primarySchoolStudent_id" = user_id__;
				RETURN school_name__;
			ELSIF info_type = 'grade' THEN
				SELECT "Grade" INTO grade__
				FROM "PrimarySchoolStudent"
				WHERE "primarySchoolStudent_id" = user_id__;
				RETURN grade__::TEXT;
			END IF;
		ELSIF user_type__ = 'HSS' THEN
			IF info_type = 'school_name' THEN
				SELECT "HighSchoolName" INTO school_name__
				FROM "HighSchoolStudent"
				WHERE "highSchoolStudent_id" = user_id__;
				RETURN school_name__;
			ELSIF info_type = 'grade' THEN
				SELECT "Grade" INTO grade__
				FROM "HighSchoolStudent"
				WHERE "highSchoolStudent_id" = user_id__;
				RETURN grade__::TEXT;
			END IF;
		ELSIF user_type__ = 'CSS' THEN
			IF info_type = 'school_name' THEN
				SELECT "CollegeName" INTO school_name__
				FROM "CollegeStudent"
				WHERE "collegeStudent_id" = user_id__;
				RETURN school_name__;
			ELSEIF info_type = 'field' THEN
				SELECT "BachelorType" INTO bachelor_type__
				FROM "CollegeStudent"
				WHERE "collegeStudent_id" = user_id__;
				RETURN bachelor_type__;
			ELSIF info_type = 'grade' THEN
				SELECT "Grade" INTO grade__
				FROM "CollegeStudent"
				WHERE "collegeStudent_id" = user_id__;
				RETURN grade__::TEXT;
			END IF;
		END IF;

	ELSE
		result := 'User not found for ID: ' || user_id__;
	END IF;
END;
$$ LANGUAGE plpgsql;

/*Girilen kullanıcı bilgileri doğru mu test eden saklı yordam*/
CREATE OR REPLACE FUNCTION "AuthenticateUser"(IN email TEXT, IN password__ TEXT)
RETURNS INT AS $$
DECLARE 
	user_id__ INT;
BEGIN 
	SELECT "user_id" INTO user_id__ 
	FROM "User" 
	WHERE "Email" = email AND "user_password" = password__;

	IF user_id__ IS NOT NULL THEN 
		RETURN user_id__;
	ELSE 
		RETURN -1;
	END IF;	
END; 
$$ LANGUAGE plpgsql;



/*Text olarak Soru ve Cevabı birleştirip veriyor*/
CREATE OR REPLACE FUNCTION "GetQuestionAndAnswer"(IN question_id__ INT)
RETURNS TEXT AS $$
DECLARE 
	question_text__ TEXT;
	answer_text__ TEXT;
	result TEXT;
BEGIN 
	-- Initialize result to an empty string
	result := '';

	-- Fetch question text
	SELECT "question_text" INTO question_text__ 
	FROM "Question" 
	WHERE "question_id" = question_id__;

	-- Check if the question exists
	IF question_text__ IS NOT NULL THEN
		-- Fetch correct answer text
		SELECT "answer_text" INTO answer_text__ 
		FROM "Answer" 
		WHERE "question_id" = question_id__;
		

		-- Concatenate question and answer texts
		IF answer_text__ IS NOT NULL THEN
			result := 'Question: ' || question_text__ || ' Answer: ' || answer_text__;
		ELSE
			result := 'Question: ' || question_text__ || ' Correct answer not found.';
		END IF;
	ELSE
		result := 'Question not found for ID: ' || question_id__;
	END IF;

	RETURN result;
END; 
$$ LANGUAGE plpgsql;


/* Chatbotun bildiği konuları sıralıyor*/
CREATE OR REPLACE FUNCTION "ConcatenateSubjects"()
RETURNS TEXT AS $$
DECLARE
    subject_list TEXT;
BEGIN
    -- Initialize the subject_list variable
    subject_list := '';

    -- Concatenate subjects
    SELECT string_agg("subject_name", ', ') INTO subject_list
    FROM "Subject";

    -- Return the concatenated subject list
    RETURN subject_list;
END;
$$ LANGUAGE plpgsql;


/* Bir konu ismi verildiğinde o konunun açıklamasını yazıyor*/
CREATE OR REPLACE FUNCTION "GetSubjectDescription"(IN subject_name_param VARCHAR(150))
RETURNS TEXT AS $$
DECLARE
    subject_description__ TEXT;
BEGIN
    -- Initialize the subject_description variable
    subject_description__ := '';

    -- Fetch subject description based on the input subject_name
    SELECT "subject_description" INTO subject_description__
    FROM "Subject"
    WHERE "subject_name" = subject_name_param;

    -- Return the subject description
    RETURN subject_description__;
END;
$$ LANGUAGE plpgsql;