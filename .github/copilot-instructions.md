# Copilot / AI Agent Instructions for DataStructers_Algorithms

Bu projede AI yardımcılarını hızlıca üretken hale getirecek, keşfedilebilir ve somut talimatlar aşağıdadır.

Özet (Big picture)
- **Kapsam:** Bu repo küçük, tek-dosya C++ veri yapıları örnekleri içeriyor (örn. çift bağlı liste). Ana dosya kök dizininde `5.c++` bulunuyor.
- **Amaç:** Eğitim amaçlı algoritma/DS gösterimleri; kodlar doğrudan derlenip çalıştırılabilecek self-contained örneklerdir.

Önemli dosyalar / örnekler
- `5.c++` — çift bağlı liste örneği, `Node`, `insertAtEnd`, `deleteNode`, `printList` fonksiyonlarını içerir ([5.c++](5.c++#L1-L400)).

Projeye özel gözlemler (etiketlenmiş, değiştirilebilir noktalar)
- Dosya uzantısı: kaynak dosya `*.c++` kullanıyor. Araçlar/CI `*.cpp` bekleyebilir — derlerken `g++ -x c++` veya dosyayı `.cpp` olarak yeniden adlandırma gerekebilir.
- Stil ve bellek yönetimi: ham pointer (`new`/`delete`) kullanılıyor; akıllı pointer yok. Bellek sızıntılarını veya çift `delete` durumlarını kontrol edecek değişikliklerde dikkatli olun.
- İsimlendirme: fonksiyonlar `camelCase` (ör. `insertAtEnd`, `deleteNode`). Yorumlar Türkçe.
- I/O kullanımı: dosyada `cout` kullanımı var ama `std::` ön eki veya `using namespace std;` net değil — otomatik düzeltmeler yaparken `std::cout` veya bir `using` satırı ekleyin.

Yapılacak işler için somut örnekler (kod tamamlama / refactor önerileri)
- Yeni örnek eklemek: mevcut patterni takip edin — `struct Node` tanımı -> bağlantı fonksiyonları (`insertAtEnd`, `deleteNode`) -> `printList`.
- Derleme talimatı örneği (yerel geliştirme):
  - `g++ -std=c++17 -O2 5.c++ -o 5 && ./5` (eğer derleyici `.c++` uzantısını destekliyorsa)
  - alternatif: `g++ -std=c++17 -O2 -x c++ 5.c++ -o 5 && ./5`
- Test / çalıştırma: kaynak dosyalarda `main` fonksiyonu yoksa AI ajanı örnek `main` eklemeli ve temel kullanım senaryolarını gösteren küçük runner oluşturmalı.

Değişiklik koruma ve PR yönergeleri
- Küçük, izole değişiklikler yapın (ör: sadece bir fonksiyon düzeltmesi). Büyük yeniden yazımlarda README veya ayrı örnek dosyası ekleyin.
- Otomatik düzeltmelerde: kodu derleyip temel çıktıyı kontrol eden bir küçük CI/manuel adım ekleyin.

Neyi değiştirmeyin otomatik olarak
- Varolan fonksiyon isimleri ve dışa dönük API (ör. `insertAtEnd`) değiştirilmemeli; sadece iç mantık düzeltmeleri ve güvenlik (null-check) iyileştirmeleri yapılabilir.

İletişim / belirsizlik durumları
- Eğer bir dosyanın amacı belirsizse (`*.c++` vs `*.cpp`), önce küçük bir PR ile `README.md` veya dosya başına kısa açıklama ekleyin.

Ek notlar
- Kodda Türkçe yorumlar bulunduğu için commit mesajlarında ve PR açıklamalarında kısa İngilizce özetler eklenmesi tercih edilir.

-- Son --
Lütfen eksik veya belirsiz gördüğünüz bölümleri söyleyin; ihtiyaç varsa benzer yönergeleri diğer örnek dosyalar için genişleteyim.
