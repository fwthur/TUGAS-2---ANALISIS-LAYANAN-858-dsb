<?php
// Fungsi sederhana untuk menghitung harga akhir setelah diskon
function hitungDiskon($harga, $persentase_diskon) {
    // Hitung total diskon
    $diskon = $harga * $persentase_diskon;
    
    // Hitung harga akhir setelah diskon
    $harga_akhir = $harga - $diskon;
    
    // Kembalikan harga akhir
    return $harga_akhir;
}

// Contoh penggunaan fungsi
$harga = 100000; // Harga produk Rp 100.000
$diskon = 0.1;   // Diskon 10%

// Panggil fungsi hitungDiskon
$harga_setelah_diskon = hitungDiskon($harga, $diskon);

// Tampilkan hasil
echo "Harga setelah diskon: Rp " . $harga_setelah_diskon;
?>