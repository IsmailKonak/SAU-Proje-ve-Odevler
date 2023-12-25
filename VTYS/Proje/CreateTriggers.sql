
-- Drop triggers
DROP TRIGGER IF EXISTS address_insert_trigger ON "Address";
DROP TRIGGER IF EXISTS user_quiz_result_insert_trigger ON "UserQuizResult";
DROP TRIGGER IF EXISTS topic_content_insert_trigger ON "Content";
DROP TRIGGER IF EXISTS subject_content_insert_trigger ON "Content";

/*	TRIGGERLAR	*/

/*Adres tablosuna her yeni kayıt eklendiğinde, sokak, mahalle, şehir ve ülke
değerlerini alarak bunları birleştirip "FullAddressText" alanına atar*/
CREATE OR REPLACE FUNCTION calculate_full_address() RETURNS TRIGGER AS $$
DECLARE 
	street__ TEXT;
	neighborhood__ TEXT;
	city__ TEXT;
	country__ TEXT;
BEGIN
	SELECT "StreetName" INTO street__ FROM "Street" WHERE "street_id" = NEW."Street";
	SELECT "NeighborhoodName" INTO neighborhood__ FROM "Neighborhood" WHERE "neighborhood_id" = NEW."Neighborhood";
	SELECT "CityName" INTO city__ FROM "City" WHERE "CityId" = NEW."City";
	SELECT "CountryName" INTO country__ FROM "Country" WHERE "CountryId" = NEW."Country";
	NEW."FullAddressText" := street__ || ' ' || neighborhood__ || ' ' || city__ || ' ' || country__;
	
	RETURN NEW;
END;
$$ LANGUAGE plpgsql;
CREATE TRIGGER address_insert_trigger
	BEFORE INSERT ON "Address"
	FOR EACH ROW
	EXECUTE PROCEDURE calculate_full_address();
	
/*UserQuizResult tablosuna yeni bir kayıt eklendiğinde, 
"Score" değerini yüzdeye çevirip "ScorePercentage" değerine atar.*/	
CREATE OR REPLACE FUNCTION calculate_score_percentage() RETURNS TRIGGER AS $$
BEGIN
	NEW."ScoreinPercentage" := ((NEW."Score"::FLOAT / (SELECT COUNT(*) FROM "Question" WHERE "quiz_id" = NEW."quiz_id")::FLOAT) * 100)::FLOAT;
	RETURN NEW;
END;
$$ LANGUAGE plpgsql;
CREATE TRIGGER user_quiz_result_insert_trigger
	BEFORE INSERT ON "UserQuizResult"
	FOR EACH ROW
	EXECUTE PROCEDURE calculate_score_percentage();
	
	
/**/
CREATE OR REPLACE FUNCTION increase_topic_content_num() RETURNS TRIGGER AS $$
BEGIN
	UPDATE "Topic"
	SET "TopicContentNum" = "TopicContentNum" + 1
	WHERE "topic_id" = NEW.topic_id;
	RETURN NEW;
END;
$$ LANGUAGE plpgsql;
CREATE TRIGGER topic_content_insert_trigger
	AFTER INSERT ON "Content"
	FOR EACH ROW
	EXECUTE PROCEDURE increase_topic_content_num();

/**/
CREATE OR REPLACE FUNCTION increase_subject_topic_content_num() RETURNS TRIGGER AS $$
BEGIN
	UPDATE "Subject"
	SET "TotalContentNum" = "TotalContentNum" + 1
	WHERE "subject_id" = (SELECT "subject_id" FROM "Topic" WHERE "topic_id" = NEW.topic_id);
	RETURN NEW;
END;
$$ LANGUAGE plpgsql;
CREATE TRIGGER subject_content_insert_trigger
	AFTER INSERT ON "Content"
	FOR EACH ROW
	EXECUTE PROCEDURE increase_subject_topic_content_num();