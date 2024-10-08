// Representasi item PSPEC
$itemPspec = [
    'nama' => 'Semen Portland',
    'deskripsi' => 'Untuk konstruksi beton',
    'jumlah' => 500,
    'satuan' => 'sak',
    'spesifikasi_teknis' => [
        'tipe' => 'PPC',
        'berat' => '50 kg',
        'standar' => 'SNI 03-2847-1992'
    ]
];

// Representasi DPPL
$dppl = [
    'nama_proyek' => 'Pembangunan Gedung Kantor',
    'list_item_pspec' => [
        $itemPspec,
        // Tambahkan item PSPEC lainnya di sini
    ]
];

// Fungsi untuk menampilkan data DPPL
function tampilkanDPPL($dppl) {
    echo "Nama Proyek: " . $dppl['nama_proyek'] . "<br>";
    echo "Daftar Item PSPEC:<br>";
    foreach ($dppl['list_item_pspec'] as $item) {
        echo "- " . $item['nama'] . " (" . $item['jumlah'] . " " . $item['satuan'] . ")<br>";
    }
}

// Memanggil fungsi untuk menampilkan data
tampilkanDPPL($dppl);