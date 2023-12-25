-- Astronomi ile ilgili konular (subject)
INSERT INTO "Subject"("subject_name","subject_description") 
VALUES('Güneş Sistemi','Güneş sistemi ile ilgili konular');

INSERT INTO "Subject"("subject_name","subject_description") 
VALUES('Yıldızlar','Yıldızlar ile ilgili konular');

INSERT INTO "Subject"("subject_name","subject_description") 
VALUES('Evren','Evren ile ilgili konular');

INSERT INTO "Subject"("subject_name","subject_description") 
VALUES('Karadelikler','Karadelikler ile ilgili konular');

INSERT INTO "Subject"("subject_name","subject_description")
VALUES('Öte Gezegenler','Öte gezegenler ile ilgili konular');

-- SELECT * FROM "Subject";

-- Güneş sistemi.
INSERT INTO "Topic"("TopicName","TopicDescription","TopicDifficulty","subject_id")
VALUES('Güneş','Güneş ile ilgili konular',1,1);
INSERT INTO "Topic"("TopicName","TopicDescription","TopicDifficulty","subject_id")
VALUES('Merkür','Merkür ile ilgili konular',1,1);
INSERT INTO "Topic"("TopicName","TopicDescription","TopicDifficulty","subject_id")
VALUES('Venüs','Venüs ile ilgili konular',1,1);
INSERT INTO "Topic"("TopicName","TopicDescription","TopicDifficulty","subject_id")
VALUES('Dünya','Dünya ile ilgili konular',1,1);
INSERT INTO "Topic"("TopicName","TopicDescription","TopicDifficulty","subject_id")
VALUES('Mars','Mars ile ilgili konular',1,1);

-- Yıldızlar
INSERT INTO "Topic"("TopicName","TopicDescription","TopicDifficulty","subject_id")
VALUES('Yıldızlar','Yıldızlar ile ilgili genel bilgiler',1,2);
INSERT INTO "Topic"("TopicName","TopicDescription","TopicDifficulty","subject_id")
VALUES('Kırmızı Cüce','Kırmızı Cüce ile ilgili konular',2,2);
INSERT INTO "Topic"("TopicName","TopicDescription","TopicDifficulty","subject_id")
VALUES('Beyaz Cüce','Beyaz Cüce ile ilgili konular',3,2);
INSERT INTO "Topic"("TopicName","TopicDescription","TopicDifficulty","subject_id")
VALUES('Kırmızı Dev','Kırmızı Dev ile ilgili konular',2,2);


-- Evren
INSERT INTO "Topic"("TopicName","TopicDescription","TopicDifficulty","subject_id")
VALUES('Evrenin Oluşumu','Evrenin Oluşumu ile ilgili konular',2,3);
INSERT INTO "Topic"("TopicName","TopicDescription","TopicDifficulty","subject_id")
VALUES('Evrenin Yaşı','Evrenin Yaşı ile ilgili konular',3,3);
INSERT INTO "Topic"("TopicName","TopicDescription","TopicDifficulty","subject_id")
VALUES('Evrenin Genişlemesi','Evrenin Genişlemesi ile ilgili konular',5,3);
INSERT INTO "Topic"("TopicName","TopicDescription","TopicDifficulty","subject_id")
VALUES('Evrenin Sonu','Evrenin Sonu ile ilgili konular',3,3);

-- Karadelikler
INSERT INTO "Topic"("TopicName","TopicDescription","TopicDifficulty","subject_id")
VALUES('Karadeliklerin Oluşumu','Karadeliklerin Oluşumu ile ilgili konular',5,4);
INSERT INTO "Topic"("TopicName","TopicDescription","TopicDifficulty","subject_id")
VALUES('Karadeliklerin Özellikleri','Karadeliklerin Özellikleri ile ilgili konular',6,4);
INSERT INTO "Topic"("TopicName","TopicDescription","TopicDifficulty","subject_id")
VALUES('Karadeliklerin Sonu','Karadeliklerin Sonu ile ilgili konular',5,4);

-- Öte Gezegenler
INSERT INTO "Topic"("TopicName","TopicDescription","TopicDifficulty","subject_id")
VALUES('Öte Gezegenlerin Keşfi','Öte Gezegenlerin Keşfi ile ilgili konular',2,5);
INSERT INTO "Topic"("TopicName","TopicDescription","TopicDifficulty","subject_id")
VALUES('Öte Gezegenlerin Özellikleri','Öte Gezegenlerin Özellikleri ile ilgili konular',3,5);
INSERT INTO "Topic"("TopicName","TopicDescription","TopicDifficulty","subject_id")
VALUES('Öte Gezegenlerin Yaşamı','Öte Gezegenlerin Yaşamı ile ilgili konular',4,5);
INSERT INTO "Topic"("TopicName","TopicDescription","TopicDifficulty","subject_id")
VALUES('Öte Gezegenlerin Geleceği','Öte Gezegenlerin Geleceği ile ilgili konular',5,5);


-- Sanal kullanıcılar (user) oluşturulmalıdır.
INSERT INTO "User"("Username","Email","user_password","UserType")
VALUES('admin','admin@admin.com','admin','CSS');

INSERT INTO "User"("Username","Email","user_password","UserType")
VALUES('Sam Altman','sam@altman.com','sam','CSS');

INSERT INTO "User"("Username","Email","user_password","UserType")
VALUES('Elon Musk','elon@musk.com','elon','CSS');

INSERT INTO "User"("Username","Email","user_password","UserType")
VALUES('Bill Gates','bill@gates.com','bill','PSS');

SELECT * FROM "Topic";
