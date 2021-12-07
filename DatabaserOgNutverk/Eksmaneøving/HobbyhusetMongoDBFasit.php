//Mongo db END ALL DOCUMENT
//Opprett  Hobbyhuset
use hobbyhuset;
//Opprett bruker hobbyhuset
db.createUser({
user: "hobby",
 pwd: "hobby",
roles: [ "readWrite", "dbAdmin" ]
  });
//Oppret en dokument samling vare
db.createCollection('vare');
//Sett in data
db.vare.insertMany ([
    {"vnr" : "33045", "betegnelse" : "Blomkarse", "pris" : 17.5, 
            "kategori" : "Blomsterfrø","antall" : 1206, "hylle" : "E05"},
    {"vnr" : "33044","betegnelse" : "Blandet blomsterfrø","pris" : 14.5,
            "kategori" : "Blomsterfrø",  "antall" : 1080, "hylle" : "E05"},
    {"vnr" : "64551","betegnelse" : "Hengebegonia 10 stk","pris" : 118,
            "kategori" : "Blomsterløker", "antall" : 206},
    {"vnr" : "55130","betegnelse" : "Moro med marsipan","pris" : 298.5,
            "kategori" : "Bøker", "antall" : 140, "hylle" : "C20"},
    {"vnr" : "21032","betegnelse" : "Furuspon, 3 cm","pris" : 57.5,
            "kategori" : "Dekorasjoner","antall" : 240, "hylle" : "B32"},
    {"vnr" : "10830","betegnelse" : "Nisseskjegg, 30 cm","pris" : 57.5,
            "kategori" : "Dukker og nisser","antall" : 42},
    {"vnr" : "13001","betegnelse" : "Glasskuler, 100 gr","pris" : 38,
            "kategori" : "Dukker og nisser","antall" : 0, "hylle" : "E11"},
    {"vnr" : "15211", "betegnelse" : "Tubeflue verktøy","pris" : 209,
            "kategori" : "Fiske","antall" : 39, "hylle" : "B42"},
    {"vnr" : "15217","betegnelse" : "Kram tørrfluekorker, 5stk","pris" : 32,
            "kategori" : "Fiske","antall" : 213, "hylle" : "B42"},
    {"vnr" : "15207","betegnelse" : "Antron garn, hvit","pris" : 24.5,
            "kategori" : "Fiske","antall" : 21, "hylle" : "B41"},
    {"vnr" : "65247","betegnelse" : "Liten plantespade","pris" : 75,
            "kategori" : "Hageutstyr","antall" : 76, "hylle" : "A25"},
    {"vnr" : "44939","betegnelse" : "Hobbymaling, 6 farger","pris" : 115,
            "kategori" : "Hobbymaling", "antall" : 2, "hylle" : "B02"},
    {"vnr" : "42615","betegnelse" : "Gipsform marihøner","pris" : 106,
            "kategori" : "Keramikk", "antall" : 124, "hylle" : "B03"},
    {"vnr" : "90164","betegnelse" : "Lakrisekstrakt, 100g","pris" : 75.5,
            "kategori" : "Konfekt og marsipan","antall" : 104, "hylle" : "B06"},
    {"vnr" : "90693","betegnelse" : "Marsipantang","pris" : 57,
            "kategori" : "Konfekt og marsipan","antall" : 0, "hylle" : "B17"}
]);
//Skriv betegnelse og kategori, sortert etter pris.
db.vare.find({},{_id:0, betegnelse:1, kategori:1}).sort({pris:1}).pretty();
db.vare.aggregate([
{
        $project: {
             _id: 0, betegnelse:1, kategori:1
         }
},
{
        $sort: {
               pris:1 
         }
}
]);
//Skriv ut data sortert etter kategori
db.vare.find().sort({kategori:1}).pretty();
//Finn alle varer der kategori inneholder strengen "er"
db.vare.find({betegnelse: /er/}).pretty();  // LIKE '%er%'
db.vare.update({betegnelse: /er/}, {betegnelse: /xxx/});
//Finn antall objekter på lager
db.vare.find().count(); //eller bare db.vare.count();
//Finn antall objekter med pris større enn 50
db.vare.count({pris: {$gt: 50}}); //andre operatorer: $eq, $gt, $gte, $in, $lt, $lte, $ne, $nin
//Finn antall hyller av hver hylletype (group)
db.vare.aggregate({$group: {_id: "$hylle", antall: { $sum: 1 } } });
Finn totalt antall varer på lager 
db.vare.aggregate([
{
    $group: { _id: '',AntallVarer: { $sum: '$antall' }}
 }, {
    $project: {
        _id: 0,
        TotaltAntallVarer: {$sum: '$AntallVarer'}
    }
}]);
//Finn total pris for varelager
//Spørringen under finner produktene av pris × antall, men summerer ikke disse tallene.
db.vare.aggregate([
{
        $project: {
             _id: 0, 
             produkt: {$multiply: ["$pris", "$antall"]}
         }
}, {
    $project: {
        _id: 0,
        produktSum: {$sum: "$produkt"}
    }
}]);