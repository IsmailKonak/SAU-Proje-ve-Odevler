
import psycopg2

def AddContent(): 
    conn = psycopg2.connect(
        host="localhost",
        database="ProjeYeniTest",
        user="postgres",
        password="Migennes1")

    cur = conn.cursor()

    # GÜNEŞ SİSTEMİ
    gunes_sistemi = [
        {"content_name": "Güneş", "text": """ Güneş, güneş sisteminin merkezinde bulunan devasa bir yıldızdır. Hidrojenin helyuma dönüştüğü termonükleer reaksiyonlarla enerji üretir. Bu enerji, ışık ve ısı olarak yayılır ve güneş sistemindeki diğer cisimleri çeker. Güneş, gezegenlerin ve gök cisimlerinin yörüngelerini belirleyen büyük kütleçekimi etkisiyle sistemin baskın çekim merkezidir."""},
        {"content_name": "Merkür", "text": """Merkür, güneş sistemindeki en küçük gezegenlerden biridir. Yüzeyi kayalık ve çorak, atmosferi neredeyse yok denecek kadar incedir. Aşırı sıcaklık değişimlerine maruz kalan Merkür, güneşe olan yakınlığı nedeniyle aşırı sıcaklık ve soğuklara sahip bir gezegendir."""},
        {"content_name": "Venüs", "text": """Venüs, atmosferindeki kalın karbon dioksit tabakasıyla bilinen bir gezegendir. Yüzeyi volkanik dağlar, dağ benzeri yapılar ve sıcaklık olarak en yüksek değerlere sahip atmosferiyle dikkat çeker. Güneşe olan yakınlığı nedeniyle Venüs, atmosferik sıcaklıklar açısından oldukça zorlu bir ortama sahiptir."""},
        {"content_name": "Dünya", "text": """Dünya, bilinen tek yaşam barındıran gezegen olarak öne çıkar. Zengin bir çeşitliliğe sahip olan Dünyanın yüzeyi okyanuslar, dağlar, vadiler ve çeşitli iklim bölgeleriyle kaplıdır. Atmosferi, yaşam için gerekli olan oksijeni içerir ve suyun sıvı halini koruyan uygun sıcaklık ve basınca sahiptir."""},
        {"content_name": "Mars", "text": """Mars, kızılımsı renkli yüzeyiyle bilinen bir gezegendir. Kutuplarında buzlu su bulunduğuna dair kanıtlar vardır. Marsın atmosferi ince olup, yüzeyinde devasa vadiler, dağlar ve eski nehir yatakları bulunur. Gezegen aynı zamanda potansiyel olarak yaşam barındırabilecek koşulları araştırmak için gönderilen uzay araştırmalarının odak noktalarından biridir."""},
    ]

    # Yıldlzar
    yildizlar = [
        {"content_name": "Yıldızlar", "text": """Yıldızlar, gökyüzündeki parlak noktalardan oluşan devasa gaz kütleli gök cisimleridir. Kendi etraflarında dönen gaz ve toz bulutlarının çekirdeklerindeki nükleer reaksiyonlarla ışık ve enerji üretirler. Yıldızlar, evrende geniş bir çeşitliliğe sahiptir ve farklı evrelerden geçerek sonunda farklı kategorilere ayrılırlar."""},
        {"content_name": "Kırmızı Cüceler", "text": """Kırmızı Cüceler, evrimlerini tamamlamış küçük yıldızlardır. Daha düşük kütleli ve soğuk oldukları için genellikle kırmızı renkte görünürler. Kırmızı cüceler, uzun bir süre boyunca yavaşça soğuyarak ve enerji üreterek varlıklarını sürdürürler."""},
        {"content_name": "Beyaz Cüceler", "text": """Beyaz Cüceler, evrimini tamamlamış ancak kırmızı cüceden daha büyük olan yıldızlardır. Çekirdeklerindeki nükleer reaksiyonlar sona erdiğinde, dış katmanları uzaya dağılır ve sadece sıcak ve yoğun bir çekirdek kalır. Bu çekirdek, beyaz renkte parlar ve beyaz cüce adını alır."""},
        {"content_name": "Kırmızı Devler", "text": """Kırmızı Devler, büyük kütleli yıldızların evrimin sonlarına doğru geçtikleri evrelerdir. Çekirdeklerindeki nükleer reaksiyonlar devam ederken dış katmanları genişleyerek kırmızımsı bir renk alır. Kırmızı devler, büyük miktarlarda enerji üretirler ve evrimlerini tamamladıktan sonra genellikle süpernova patlamalarıyla son bulurlar."""},
    ]

    # Evren
    evren = [
        {"content_name": "Evren", "text": """Evrenin oluşumu, Büyük Patlama teorisi ile açıklanır. Bu teoriye göre, 13.8 milyar yıl önce evren, yoğun ve sıcak bir durumda bulunan tek bir noktadan patlayarak genişlemeye başlamıştır. Bu patlama sonucunda madde, enerji, zaman ve uzay oluşmuş ve evrenin bugünkü hali ortaya çıkmıştır."""},
        {"content_name": "Evrenin Yaşı", "text": """Evrenin yaşı, Büyük Patlamanın ardından geçen süreye denk gelir ve tahmini olarak 13.8 milyar yıl olarak kabul edilir. Evrenin yaşının belirlenmesinde, uzaydaki uzak galaksilere olan gözlemler, kozmik mikrodalga arka plan radyasyonunun ölçümleri ve diğer kozmolojik gözlemler kullanılır."""},
        {"content_name": "Evrenin Genişlemesi", "text": """Evrenin genişlemesi, galaksilerin birbirinden uzaklaştığını gösteren bir fenomendir. Hubble Sabitinin keşfiyle ortaya çıkan bu genişleme, galaksilerin birbirinden uzaklaşmasıyla evrenin genişlediğini gösterir. Genişleme, evrenin geçmişte daha yoğun ve sıcak olduğu bir noktadan başlamış olabilir."""},
        {"content_name": "Evrenin Sonu", "text": """Evrenin sonu, şu ana kadar net bir şekilde belirlenmemiştir. Bazı teorilere göre evren, sürekli genişleyerek soğuyacak ve sonunda ısı ölümüne ulaşacaktır. Diğer teoriler ise evrenin genişlemesinin yavaşlayarak bir çöküşe neden olabileceğini veya evrenin sonsuz bir genişleme sürecine girebileceğini öne sürer. Bu konudaki bilgilerimiz ve teorilerimiz gün geçtikçe güncellenmektedir."""}
    ]

    # Karadelikler
    karadelikler = [
        {"content_name": "Karadelikler", "text": """Karadelikler, devasa kütlelere sahip yıldızların evrimin sonunda çekirdeklerinde gerçekleşen çökme sonucunda ortaya çıkarlar. Yıldızın çekirdeğindeki nükleer yakıt tükendiğinde, dış katmanlar uzaya saçılır ve çekirdek aşırı yoğunlaşarak karadelik oluşturur. Çekim kuvveti o kadar güçlüdür ki ışık bile ondan kaçamaz, bu nedenle karadelikler kara ve görünmez olarak tanımlanır."""},
        {"content_name": "Karadeliklerin Özellikleri", "text": """Karadeliklerin özellikleri arasında kütlesel çekimleri nedeniyle ışığın dahi kaçamadığı olay ufku bulunur. Karadelikler, kara delik ve hızla dönen kara delik gibi farklı türlerde olabilirler. Karadelikler, çevrelerindeki maddeyi emer ve bu maddeyi çekirdeklerine çekerler. Yüksek enerjili parçacıkların ve x ışınlarının kaynağı olabilirler."""},
        {"content_name": "Hawking Işıması", "text": """Karadeliklerin sonu, Stephen Hawking tarafından öne sürülen Hawking ışıması teorisi doğrultusunda açıklanır. Bu teoriye göre, karadelikler kendi kütlelerini radyasyonla kaybederler ve sonunda tamamen buharlaşırlar. Bu süreç, karadeliklerin varlıklarını sürdürebilmeleri için çekirdeğindeki nükleer yakıtın tükenmesinden sonra ortaya çıkar. Hawking ışıması, karadeliklerin evrenin uzun vadeli evriminde önemli bir rol oynadığını düşündürmektedir."""},
    ]

    # Öte Gezegenler
    ote_gezegenler = [
        {"content_name": "Öte Gezegenlerin Keşfi", "text": """Öte Gezegenlerin keşfi, teknolojik gelişmeler sayesinde artan hassasiyetle yapılan teleskop gözlemleri ve uzay misyonlarıyla gerçekleşmektedir. İlk öte gezegen keşfi, 1992de keşfedilen bir yıldızın etrafında dönen bir gezegenle yapılmıştır."""},
        {"content_name": "Öte Gezegenlerin Özellikleri", "text": """Öte Gezegenlerin özellikleri, büyüklükleri, yüzey sıcaklıkları, atmosfer bileşenleri ve yıldızları etrafındaki yörüngeleri gibi bir dizi faktöre bağlıdır. Birçok öte gezegen, Dünyaya benzer koşullara sahip olabilir ya da tamamen farklı bir yapıya sahip olabilir."""},
        {"content_name": "Öte Gezegenlerde Yaşam Arayışı", "text": """Öte Gezegenlerde yaşam arayışı, su varlığı, uygun sıcaklık ve atmosfer koşulları gibi faktörlere odaklanır. Bilim insanları, öte gezegenlerde mikroorganizmaların varlığını belirleme amacıyla gelecekteki uzay görevlerini planlamaktadırlar. Şu ana kadar keşfedilen öte gezegenler arasında potansiyel yaşam barındırma olasılığı olanlar da bulunmaktadır."""},
        {"content_name": "Öte Gezegenlerin Geleceği", "text": """Öte Gezegenlerin geleceği, teknolojik gelişmeler ve uzay gözlemleriyle yakından ilgilidir. Gelecekteki teleskoplar ve uzay misyonları, öte gezegenlerin daha ayrıntılı bir şekilde incelenmesine ve potansiyel yaşam belirtilerinin araştırılmasına olanak tanıyacaktır. Bu çalışmalar, evrende yaşamın var olup olmadığını anlamak adına önemli ipuçları sunabilir."""},
    ]

    """
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
    """

    # Güneş Sistemi
    for i, dict in enumerate(gunes_sistemi):
        cur.execute(f""" INSERT INTO "Content" ("ContentName", "ContentText", "topic_id")
                        VALUES ('{dict["content_name"]}', '{dict["text"]}', {i+1})""")
        conn.commit()
        
    # Yıldızlar
    for i, dict in enumerate(yildizlar):
        cur.execute(f""" INSERT INTO "Content" ("ContentName", "ContentText", "topic_id")
                        VALUES ('{dict["content_name"]}', '{dict["text"]}', {i+6})""")
        conn.commit()
        
    # Evren
    for i, dict in enumerate(evren):
        cur.execute(f""" INSERT INTO "Content" ("ContentName", "ContentText", "topic_id")
                        VALUES ('{dict["content_name"]}', '{dict["text"]}', {i+10})""")
        conn.commit()
        

    # Karadelikler
    for i, dict in enumerate(karadelikler):
        cur.execute(f""" INSERT INTO "Content" ("ContentName", "ContentText", "topic_id")
                        VALUES ('{dict["content_name"]}', '{dict["text"]}', {i+14})""")
        conn.commit()
        
    # Öte Gezegenler
    for i, dict in enumerate(ote_gezegenler):
        cur.execute(f""" INSERT INTO "Content" ("ContentName", "ContentText", "topic_id")
                        VALUES ('{dict["content_name"]}', '{dict["text"]}', {i+17})""")
        conn.commit()


    print("İçerikler başarıyla eklendi.")
    # cur.execute("SELECT * FROM \"Content\"")
    # rows = cur.fetchall()
    # for row in rows:
    #     print(row)

    conn.close()