# Gorev-7

***Önemli Not:*** `valarray` ileri düzey C++ yazılımcılarının bile duymamış olabileceği kullanılmayan ve derleyici desteğinin kaldırıldığı bir standart kütüphane.
Bu görevi en sık kullanılan yapıyı (`vector`) kullanarak tamamlayabilirsiniz.
`valarray` kullanmanın avantajı matris işlemlerini ve dökümantasyon kullanımını pekiştirmek denilebilir.
Ayrıntılı açıklama için [`valarray` vs `vector` sorusuna verilen cevaba](https://stackoverflow.com/a/1602787/12447766) başvurabilirsiniz.

---

7\. görev *command line argument* ve `valarray` kullanımı ile ilgili
Kullanıcıdan argüman olarak bir katsayı, satır sayısı ve matris için bir sayı dizisi alıyoruz.
Daha sonra bu dizi ve satır sayısı ile matrisi oluşturup **ilk satırı** katsayı ile çarparak ekrana yazdırıyoruz.

Argümanlar program çağrılırken kullanıcının tanımladığı girdiler oluyor. Tekrar derleme gerektirmeden argüman sayısına bağlı olarak programa farklı işlemler yaptırılabilir. Mesela dosya yolu özellikle belirtilmemişse varsayılan bir konumdan okunabilir.
*DevC++* kullanıyorsanız argümanlar *Execute/Parameters...* seçeneğiyle verilebilir. Terminalden ise şu şekilde yapabilirsiniz:
`./[executable path] [arg1] [arg2] [arg3] ...`
Argümanları almak için ana fonksiyonun girdi kısmını düzenlemek gerekiyor:
```
int main(int argc, char* argv[])
```
Burada `argc` argüman sayısı, `argv` ise argümanları tutan cstring array oluyor.
Mesela `./test.exe example argument` için **argc=3, argv[0]="./test.exe", argv[1]="example"**, 2. argümanın uzunluğu ise **sizeof(argv[2])/sizeof(char)=8** olur.

```
örnek input : ./test 2 3 4 5 6 7 8 9
örnek output : 8 10
               6 7
               8 9
```

`valarray` kullanmamızın sebebi [vektör işlemleri](https://en.wikipedia.org/wiki/Vector_processor#Description) yapabilmeye olanak sağlaması. Dokümantasyonuna [buradan](https://en.cppreference.com/w/cpp/numeric/valarray) erişebilirsiniz.


*slice* kullanımları için güzel bir [örnek](http://www.cplusplus.com/reference/valarray/gslice/)


**Matris oluşturacağımız için iki boyutlu erişim sağlamamız gerekiyor, ancak *valarray*'i amacına uygun kullanabilmemiz için hafızada ardışık gelmesi gerekiyor, yani *slice* kullanarak tek boyutlu *valarray* üzerinde işlem yapmak gerekiyor.**
https://stackoverflow.com/questions/39841525/accessing-column-slices-of-2d-valarrays#39841823

* Argümanları cstring olarak aldığımız için numerik işlemler yapmak istediğimizde bunları sayıya çevirmemiz gerekiyor. Bunun için `<stdlib.h>` kütüphanesinden `atoi` ve `atof` fonksiyonlarını kullanabilirsiniz.

* İsteyen `valaray` yerine `vector< vector<float> >` kullanabilir

**Ek not:** `slice_array<T>` ile bir katsayıyı çarpmak istiyorsak elemanları o katsayıya eşit ve boyutu slice_array boyutunda bir valarray oluşturmak gerekiyor. Yoksa normalde `valarray<T>` ile `T` türlerinin çarpımı tanımlı.
