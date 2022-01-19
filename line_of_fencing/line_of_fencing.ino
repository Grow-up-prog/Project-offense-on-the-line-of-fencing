//PROJECT line-of-fencing
//pendefinisian pin I/O
int relaySatu = 11; 
int relayDua = 12;
int relayTiga = 13;
int buzzer = 10;
int sensorA = 8;
int sensorB = 9;
int a; //pendefinisian penyimpanan

//fungsi KONDISI AMAN
int kondisiA(){//lampu hijau
    digitalWrite(relaySatu, LOW);
    digitalWrite(relayDua, LOW);
    digitalWrite(relayTiga, HIGH);
    digitalWrite(buzzer, LOW); 
  }
//fungsi KONDISI AWAS
int kondisiB(){//lampu kuning
    digitalWrite(relaySatu, HIGH);
    digitalWrite(relayDua, LOW);
    digitalWrite(relayTiga, LOW);
    digitalWrite(buzzer, LOW);  
  } 
//fungsi KONDISI PELANGGARAN
int kondisiC(){//lampu merah
    digitalWrite(relaySatu, LOW);
    digitalWrite(relayDua, HIGH);
    digitalWrite(relayTiga, LOW);
    digitalWrite(buzzer, HIGH);  
  }
//setup awal
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//melakukan set Serial untuk melakukan pembacaan
  Serial.print("PROJECT line-of-fencing"); //melakukan printing nama project
  pinMode(relaySatu, OUTPUT); //penentuan fungsi pin
  pinMode(relayDua, OUTPUT); //penentuan fungsi pin
  pinMode(relayTiga, OUTPUT); //penentuan fungsi pin
  pinMode(buzzer, OUTPUT); //penentuan fungsi pin
  pinMode(sensorA, INPUT); //penentuan fungsi pin
  pinMode(sensorB, INPUT); //penentuan fungsi pin
  int a=0; //penentuan nilai awal a = 0
}
//perulangan
void loop() {
  if(a==0){//melakukan pengecekan kondisi a, apabila sama dengan 0 maka kondisi akan dijalankan
    Serial.print("nilai a adalah= ");
    Serial.println(a);//melakukan print nilai a, maka didapatkan hasil nilai a = 0
    kondisiA(); //memanggil fungsi, dan menjalankannya 
    if(digitalRead(sensorA)==0){ //apabila sensor(jenis sensor active low, apabila mendeteksi maka logic bernilai 0) maka, 
      a+=1; //mendeteksi adanya objek maka nilai a++.
     }
     delay(100);//melakukan delay selama 100ms
  } else if(a==1){ //jika nilai a sama dengan 1 maka kondisi akan dijalankan
      Serial.print("nilai a adalah"); 
      Serial.println(a);//melakukan print nilai a, a = 1 
      kondisiB();//memanggil fungsi B, dan mejalankannya
      delay(100);//delay 100ms
      if(digitalRead(sensorB)==0){//apabila sensor(jenis sensor active low, apabila mendeteksi maka logic bernilai 0) maka, 
        a+=1; //mendeteksi adanya objek maka nilai a++.
        }
  } else if(a==2){ //jika nilai a sama dengan 2 maka kondisi akan dijalankan
    Serial.print("nilai a adalah= ");
    Serial.println(a);//melakukan print nilai a, a = 2
    kondisiC(); //memanggil fungsi pelanggaran(lampu merah menyala dan buzzer berbunyi)
    delay(2000); //melakukan delay sebanyak 2 detik
    a=0; //a di set menjadi 0 kembali
  } 
 }
