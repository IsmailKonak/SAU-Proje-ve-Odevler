DROP TABLE IF EXISTS "UserAnswer";
DROP TABLE IF EXISTS "UserQuizResult";
DROP TABLE IF EXISTS "Answer";
DROP TABLE IF EXISTS "Question";
DROP TABLE IF EXISTS "Quiz";
DROP TABLE IF EXISTS "Content";
DROP TABLE IF EXISTS "Topic";
DROP TABLE IF EXISTS "Subject";
DROP TABLE IF EXISTS "PrimarySchoolStudent";
DROP TABLE IF EXISTS "HighSchoolStudent";
DROP TABLE IF EXISTS "CollegeStudent";
DROP TABLE IF EXISTS "User";
DROP TABLE IF EXISTS "Address";
DROP TABLE IF EXISTS "City";
DROP TABLE IF EXISTS "Country";
DROP TABLE IF EXISTS "Neighborhood";
DROP TABLE IF EXISTS "Street";


CREATE TABLE "Country"(
	"CountryId" SERIAL PRIMARY KEY,
	"CountryName" VARCHAR(70) NOT NULL
);

CREATE TABLE "City" (
	"CityId" SERIAL PRIMARY KEY,
	"CityName" VARCHAR(100) NOT NULL
);

CREATE TABLE "Neighborhood" (
	"neighborhood_id" SERIAL PRIMARY KEY,
	"NeighborhoodName" VARCHAR(100) NOT NULL
);

CREATE TABLE "Street" (
	"street_id" SERIAL PRIMARY KEY,
	"StreetName" VARCHAR(100) NOT NULL
);
/* mahalle ilçe il falan bunları sırası ile birleştirerek fulladreestext i doldurucam trigger*/
CREATE TABLE "Address"(
	"address_id" SERIAL PRIMARY KEY,
	"FullAddressText" TEXT,
	"City" INT NOT NULL,
	"Country" INT NOT NULL,
	"Neighborhood" INT NOT NULL,
	"Street" INT NOT NULL,

	CONSTRAINT fk_city
		FOREIGN KEY("City") REFERENCES "City"("CityId") ,	
	CONSTRAINT fk_country
		FOREIGN KEY("Country") REFERENCES "Country"("CountryId"),
	CONSTRAINT fk_neighborhood
		FOREIGN KEY("Neighborhood") REFERENCES "Neighborhood"("neighborhood_id"),
	CONSTRAINT fk_street
		FOREIGN KEY("Street") REFERENCES "Street"("street_id")

);

CREATE TABLE "User"(
	"user_id" SERIAL PRIMARY KEY,
	"Username" VARCHAR(150) NOT NULL,
	"Email" VARCHAR(150) NOT NULL,
	"user_password" VARCHAR(150) NOT NULL,
	"RegistrationDate" DATE,
	"UserType" CHAR(3),	
	"Address" INT,
	CONSTRAINT fk_Address
		FOREIGN KEY("Address") REFERENCES "Address"("address_id")
);

CREATE TABLE "PrimarySchoolStudent"(
	"primarySchoolStudent_id" INT PRIMARY KEY,
	"PrimarySchoolName" VARCHAR(75),
	"Grade" INT,
	
	CONSTRAINT disjoint_tekc_pss
		FOREIGN KEY("primarySchoolStudent_id") REFERENCES "User"("user_id")
		ON DELETE CASCADE 
		ON UPDATE CASCADE
);

CREATE TABLE "HighSchoolStudent"(
	"highSchoolStudent_id" INT PRIMARY KEY,
	"HighSchoolName" VARCHAR(75),
	"Grade" INT,
	
	CONSTRAINT disjoint_tekc_hss
		FOREIGN KEY("highSchoolStudent_id") REFERENCES "User"("user_id")
		ON DELETE CASCADE 
		ON UPDATE CASCADE
);

CREATE TABLE "CollegeStudent"(
	"collegeStudent_id" INT PRIMARY KEY,
	"CollegeName" VARCHAR(75),
	"BachelorType" VARCHAR(75),
	"Grade" INT,
	
	CONSTRAINT disjoint_tekc_cs
		FOREIGN KEY("collegeStudent_id") REFERENCES "User"("user_id")
		ON DELETE CASCADE 
		ON UPDATE CASCADE
);

CREATE TABLE "Subject"(
	"subject_id" SERIAL PRIMARY KEY,
	"subject_name" VARCHAR(150) NOT NULL,
	"subject_description" TEXT,
	"TotalContentNum" INT DEFAULT 0 
);

CREATE TABLE "Topic"(
	"topic_id" SERIAL PRIMARY KEY,
	"TopicName" VARCHAR(150) NOT NULL,
	"TopicDescription" TEXT,
	"TopicDifficulty" INT,
	"subject_id" INT NOT NULL,
	"TopicContentNum" INT DEFAULT 0,
	
	CONSTRAINT fk_subject
		FOREIGN KEY("subject_id") REFERENCES "Subject"("subject_id")
);

CREATE TABLE "Content"(
	"content_id" SERIAL PRIMARY KEY,
	"ContentName" VARCHAR(150) NOT NULL,
	"ContentText" TEXT,
	"ImageLink" TEXT,
	"VideoLink" TEXT,
	"topic_id" INT NOT NULL,
	CONSTRAINT fk_topic
		FOREIGN KEY("topic_id") REFERENCES "Topic"("topic_id")
);

CREATE TABLE "Quiz"( 
	"quiz_id" SERIAL PRIMARY KEY,
	"quiz_name" VARCHAR(150) NOT NULL,
	"quiz_description" TEXT,
	"quiz_difficulty" INT,
	"topic_id" INT NOT NULL,
	CONSTRAINT fk_topic
		FOREIGN KEY("topic_id") REFERENCES "Topic"("topic_id")
);

CREATE TABLE "Question"(
	"question_id" SERIAL PRIMARY KEY,
	"question_text" TEXT NOT NULL,
	"question_difficulty" INT,
	"quiz_id" INT NOT NULL,
	CONSTRAINT fk_quiz
		FOREIGN KEY("quiz_id") REFERENCES "Quiz"("quiz_id")
);

CREATE TABLE "Answer"(
	"answer_id" SERIAL PRIMARY KEY,
	"answer_text" TEXT NOT NULL,
	"question_id" INT NOT NULL UNIQUE,
	CONSTRAINT fk_question
		FOREIGN KEY("question_id") REFERENCES "Question"("question_id")
);

CREATE TABLE "UserAnswer"(
	"useranswer_id" SERIAL PRIMARY KEY,
	"UserAnswerText" TEXT NOT NULL,
	"AnswerScore" REAL NOT NULL,
	"answer_id" INT NOT NULL,
	"user_id" INT NOT NULL,

	CONSTRAINT fk_answer
		FOREIGN KEY("answer_id") REFERENCES "Answer"("answer_id"),

	CONSTRAINT fk_user
		FOREIGN KEY("user_id") REFERENCES "User"("user_id")
);

/* Notu yüzdeye çevirecek trigger */
CREATE TABLE "UserQuizResult"(
	"userquizresult_id" SERIAL PRIMARY KEY,
	"Score" INT NOT NULL,
	"ScoreinPercentage" FLOAT ,
	"quiz_id" INT NOT NULL,
	"user_id" INT NOT NULL,
	"AttempDate" DATE NOT NULL,

	CONSTRAINT fk_quiz
		FOREIGN KEY("quiz_id") REFERENCES "Quiz"("quiz_id"),

	CONSTRAINT fk_user
		FOREIGN KEY("user_id") REFERENCES "User"("user_id")
);