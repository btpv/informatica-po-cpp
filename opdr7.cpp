#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>
using namespace std;

map<string, map<string, string>> antwoorden = {
{"nl", {
  {"c", "ja"},
  {"d", "nee"}
}},
{"en", {
  {"c", "yes"},
  {"d", "no"}
}}
};

map<string, string> vragen[27] = {
 {   
  {"nl", "Zin om te sporten?"},
  { "en", "Feel like playing sports?"}
},
{
    {"nl", "Hol je graag achter een bal aan?"},
    { "en", "Do you like to run after a ball?"}
},
{
    {"nl", "Bang om te zweten?"},
    { "en", "Afraid to sweat?"}
},
{
    {"nl", "Kun je er tegen wanneer iemand anders eerder bij de bal is?"},
    { "en", "Can you stand it when someone else gets to the ball before you?"}
},
{
    {"nl", "Speel je graag over?"},
    { "en", "Do you like to play over?"}
},
{
    {"nl", "Wil je per se iets met de bal doen?"},
    { "en", "Do you necessarily want to do something with the ball?"}
},
{
    {"nl", "Ben je zo snel dat niemand ooit de bal van je afpakt?"},
    { "en", "Are you so fast that no one ever takes the ball from you?"}
},
{
    {"nl", "Wil je graag tegen iemand anders sporten?"},
    { "en", "Would you like to play sports against someone else?"}
},
{
    {"nl", "Heb je een lange adem?"},
    { "en", "Do you have long breath?"}
},
{
    {"nl", "Ben je lenig?"},
    { "en", "Are you nimble?"}
},
{
    {"nl", "Wil je stoer overkomen als je sport?"},
    { "en", "Do you want to appear tough when you play sports?"}
},
{
    {"nl", "Ben je een pietje precies?"},
    { "en", "Are you a wuss?"}
},
{
    {"nl", "Hou je van spanning en snelheid?"},
    { "en", "Do you like excitement and speed?"}
},
{
    {"nl", "Vind je het al erg als je moet staan tijdens je sport?"},
    { "en", "Do you mind at all if you have to stand during your sport?"}
},
{
    {"nl", "Dus je zit graag op de bank?"},
    { "en", "So you like to sit on the couch?"}
},
{
    {"nl", "Denk je graag diep na?"},
    { "en", "Do you like to think deeply?"}
},
{
    {"nl", "Hou je van dieren?"},
    { "en", "Do you like animals?"}
},
{
    {"nl", "Wat heb je bij de eerste vraag van deze test gekozen?"},
    { "en", "What did you choose on the first question of this test?"}
},
{
    {"nl", "Zin in een spelletje?"},
    { "en", "Fancy a game?"}
},
{
    {"nl", "Is het erg als je veel erbij moet bewegen?"},
    { "en", "Is it bad if you have to move around a lot with it?"}
},
{
    {"nl", "Mag het echt niet op een sport lijken?"},
    { "en", "Should it really not look like a sport?"}
},
{
    {"nl", "Houd je van feestjes?"},
    { "en", "Do you like parties?"}
},
{
    {"nl", "Denk je dan ook?"},
    { "en", "Do you think so?"}
},
{
    {"nl", "Gebruik je je hersens graag?"},
    { "en", "Do you like to use your brain?"}
},
{
    {"nl", "Een computerspelletje dan?"},
    { "en", "A computer game then?"}
},
{
    {"nl", "Ongezellig zeg! Ben je boos?"},
    { "en", "Unsociable say! Are you angry?"}
},
{
{"nl", "Op een bepaald iemand?"},
{"en", "At a certain someone?"}
}
};

vector<string> eerste_vraag = {"welke taal wil je?","what language do you want?"};
vector<string> talen = {"nl", "en"};
map<string, string> adviezen[11] = 
{
  {
  {"nl", "De sportende allemansvriend. Jij kunt fantastisch sporten in een team. ledere andere speler kan best goed met je vinden in het sportveld. Dat kan aan twee dingen liggen. Of je bent verschrikkelijk aardig - je speelt altijd over, zelfs naar de grootste prutsers uit je team. Of je bent ontzettend goed - als jij de bal hebt, dan valt er altijd een doelpunt. In leder geval: je past uitstekend in bijna elk sportteam. Sporten: voetbal, hockey, basketbal, handbal. Jij wordt net zo goed als: Ruud van Nistelrooy."},
  {"en", "The sportsmanlike friend. You can play great sports on a team. Every other player gets along with you on the sports field. This can be due to two things. Either you are terribly nice-you always play over, even to the biggest pros of your team. Or you are incredibly good-when you have the ball, you always score a goal. In any case: you fit perfectly into almost any sports team. Sports: soccer, field hockey, basketball, handball. You will be as good as: Ruud van Nistelrooy."}
  },
  {
  {"nl", "De lange adem-sporter. Als jij eenmaal je sportkleren aan heb, ben je niet meer te stoppen. Je wordt ook liever niet afgeleid door een bal, of zeurende teamgenoten. Een race tegen de klok vindt jij al spannend genoeg. Als er toch andere sporters naast je lopen, zwemmen, of fietsen, probeer je zo snel mogelijk bij ze weg te komen. Sporten: hardlopen, zwemmen, wielrennen, atletiek. Jij wordt net zo goed als: Leontien van Moorsel."},
  {"en", "The long breath athlete. Once you've got your sports jersey on, you're unstoppable. You prefer not to be distracted by a ball or nagging teammates. You find a race against the clock exciting enough. If other athletes are running, swimming or cycling next to you, you try to get away from them as quickly as possible.Sports: running, swimming, cycling, athletics. You will be as good as: Leontien van Moorsel."}
  },
  {
  {"nl","Beweeglijke sporter. Jij wringt je lichaam het liefst in de vreemdste bochten. Als je maar kunt bewegen dansen, springen, duiken of koprollen - dan wordt je vanzelf blij. Misschien heb je er nooit echt aan gedacht om een sport te gaan doen en sta je veel liever in de discotheek to swingen. Dan moet je toch eens bij jazzballet gaan kijken. Houd je wel van sporten, dan zijn er genoeg mogelijkheden. Nu veel Nederlandse topturners geblesseerd zijn, kunnen we bijvoorbeeld nog wel wat turntalenten gebruiken! Sporten: turnen, jazzballet, stijldansen, schoonspringen, kunstschaatsen. Jij wordt net zo goed als: Verona van der Leur."},
  {"en","Agile athlete. You prefer to twist your body into the strangest corners. As long as you can move dance, jump, dive or somersault - then you automatically become happy. Maybe you have never really thought about taking up a sport and would much rather be swinging in the disco. Then you should check out jazz ballet. If you do like sports, there are plenty of opportunities. Now that many Dutch top gymnasts are injured, for example, we can still use some more gymnastic talents! Sports: gymnastics, jazz ballet, ballroom dancing, show jumping, figure skating. You will be as good as: Verona van der Leur."}
  },
  {
  {"nl","Stilstaande sporter. Jij hebt medelijden met die mensen die zich een ongeluk zweten op het sportveld. Je vindt het ook een beetje overdreven: al dat geput en gehijg. Je gooit liever met een glas drinken in je hand wat pijltjes naar een dartbord, of je schiet op een familiefeestje met pijl en boog. Misschien ben jij ook wel niet in de wieg gelegd om sporter te worden. Maar kijk eens naar Raymond van Barneveld. Ziet hij er zo getraind uit? Precies! En zijn prijzenkast staat wel vol! D1) Eigenlijk hoor jij bij de Bankzitters. Maar je hebt één voordeel: je bent boos of chagrijnig door één persoon. Plak zijn of haar foto op een dartbord, en misschien zit er toch nog een carrière als topsporter in. Sporten: darten, handboogschieten, kleiduivenschieten, bowlen. Jij wordt net zo goed als: Raymond van Barneveld."},
  {"en","Stationary athlete. You feel sorry for those people who sweat themselves to death on the sports field. You also think it's a bit excessive: all that puking and panting. You'd rather throw some darts at a dartboard with a glass of drink in your hand, or shoot a bow and arrow at a family party. Maybe you too are not cut out to be an athlete. But look at Raymond van Barneveld. Does he look that trained? Exactly! And his trophy cabinet is full though! D1) Actually, you belong to the Benchwarmers. But you have one advantage: you are angry or grumpy because of one person. Stick his or her picture on a dartboard, and maybe a career as a top athlete is in it after all. Sports: darts, hand archery, skeet shooting, bowling. You will be as good as: Raymond van Barneveld."}
  },
  {
  {"nl", "Denksporter. Als jij alles wat in je gedachten hebt, ook zou kunnen uitvoeren, dan was je misschien een topsporter geweest. Maar je lichaam doet meestal niet precies wat je hersenen willen. terwijl je denkt aan een prachtig kopbal, stuitert een voetbal op je neus. En als je in gedachte een prachtige salto uitvoert, val je uit de ringen bij het turnen. Misschien denk je daarom wel dat sporten niets voor jou is. Onzin! Want als het om denksporten gaat, laat je de spectaculairste stunts zien. Op het schaak- en dambord maak jij nooit blunders. Sporten: schaken, dammen, bridgen, klaverjassen Jij wordt net zo goed als: Gary Kasparov."},
  {"en", "Thinker. If you could execute everything in your mind, you might be a top athlete. But your body usually doesn't do exactly what your brain wants. while you're thinking of a beautiful header, a soccer ball bounces on your nose. And while your mind is performing a beautiful somersault, you fall out of the rings in gymnastics. Maybe that's why you think sports are not for you. Nonsense! Because when it comes to mind sports, you perform the most spectacular stunts. On the chess and checkers board, you never make blunders. Sports: chess, checkers, bridge, trebles You will be as good as: Gary Kasparov."}
  },
  {
  {"nl","De vechtjas-sporter. Jij werkt graag zoveel mogelijk mensen tegen de grond. Misschien kun je met de meeste personen gewoon niet zo heel erg goed opschieten. Of je hebt wel veel vrienden, maar je vindt het gewoon stoer om te laten zien hoe sterk, fit en lenig je bent. Met jou valt in ieder geval niet te spotten! Sporten: Judo, boksen, karate, jiujitsu Jij wordt net zo goed als: Mohammed Ali."},
  {"en","The hoodlum athlete. You like to work as many people against the ground as possible. Maybe you just don't get along very well with most people. Or you have a lot of friends, but you just like to show off your strength, fitness and agility. Either way, you are not to be trifled with! Sports: Judo, boxing, karate, jiujitsu You will be as good as: Muhammad Ali."}
  },
  {
  {"nl","Sportende snelheidsduivel. De meeste sporten gaan jou véél te langzaam. Hardlopen, fietsen, zwem- men, paardrijden: houd maar op, denk je als je die woorden hoort. Jij gaat je echt niet in het zweet werken om met een slakkengangetje vooruit te komen. Dan zit jij liever achter de computer en doe je net alsof je over de snel- weg schiet. Of je springt in je vrije tijd aan een elastiek van een brug. Snelheid, spanning en sensatie, daar trek jij je sportkleren voor aan. Sporten: autoracen, motorracen, bungeejumpen, paragliden Jij wordt net zo goed als: Michael Schumacher."},
  {"en","Sports speed demon. Most sports are way too slow for you. Running, cycling, swimming, horseback riding: stop, you think when you hear those words. You're not going to work up a sweat just to move at a snail's pace. You'd rather sit at the computer and pretend you're shooting down the highway. Or you jump from a bridge on a rubber band in your spare time. Speed, excitement and thrills, that's what you put on your sports clothes for. Sports: car racing, motorcycle racing, bungee jumping, paragliding You will become as good as: Michael Schumacher."}
  },
  {
  {"nl","Diervriendelijke sporter. Op zich lijkt het jou wel aardig om iets aan sport te doen. Maar je wilt liever niet buiten adem raken, of je hebt gewoon niet zo veel aanleg voor rennen en springen. Gelukkig ben je een dierenvriend. Daarom kun je op de rug van een paard, of desnoods een olifant meeliften tijdens een sportwedstrijd. Het dier doet al het werk wel! Er ligt een grote toekomst voor jou op de manege of op het poloveld. Sporten: Paardrijden, polo, olifantenpolo. Jij wordt net zo goed als: Anky van Grunsven."},
  {"en","Animal-friendly athlete. On your own, you seem to like doing something about sports. But you'd rather not run out of breath, or you just don't have much aptitude for running and jumping. Fortunately, you are an animal lover. That's why you can hitch a ride on the back of a horse, or an elephant if necessary, during a sporting event. The animal will do all the work! There is a great future ahead of you at the equestrian center or on the polo field. Sports: Horseback riding, polo, elephant polo. You will be as good as: Anky van Grunsven."}
  },
  {
  {"nl", "Bankzitter. Jij bent zo lui als een tamme cavia. Alle sporten kunnen jou eigenlijk gestolen worden. Je hebt een grote hekel aan alles wat met bewegen en inspanning te maken heeft. Misschien wil je het niet helemaal toegeven, maar eigenlijk zit je het liefst de hele dag lekker onderuitgezakt op een stoel chips te knabbelen, of televisie te kijken. Als je ooit in een gekke bui beslist om toch te gaan sporten, schrijf je dan in bij een sportteam waarin te veel spelers zitten. Dan kun je tenminste nog op de bank gaan zitten. Sporten: geen. Jij wordt net zo goed als: Winston Bogarde (bankzitter bij Chelsea)."},
  {"en","Bank sitter. You are as lazy as a tame guinea pig. All sports can basically be stolen from you. You hate anything to do with exercise and exertion. You may not fully want to admit it, but in fact, you prefer to sit in a chair all day snuggled up nibbling chips, or watching television. If you ever decide in a crazy mood to play sports anyway, sign up for a sports team that has too many players. At least then you can sit on the bank. Sports: none. You will be as good as: Winston Bogarde (benchwarmer at Chelsea)."}
  },
  {
  {"nl", "Balverliefde sporter. Jij bent gek op de bal. Je begrijpt niet waarom de spelers van een hockey, handbal, basketbal, of voetbalteam niet gewoon allemaal een eigen bal krijgen. Dan hoef je het ding ook niet steeds van elkaar af te pakken. Zelf speel je daarom liever sporten waarbij iedereen evenveel tijd krijgt om iets met een bal, of shuttle te doen. Sporten: tennis, bowlen, golfen, tafeltennis, squash, badminton. Jij wordt net zo goed als: Martin Verkerk."},
  {"en", "Balverliefde sporter. Jij bent gek op de bal. Je begrijpt niet waarom de spelers van een hockey, handbal, basketbal, of voetbalteam niet gewoon allemaal een eigen bal krijgen. Dan hoef je het ding ook niet steeds van elkaar af te pakken. Zelf speel je daarom liever sporten waarbij iedereen evenveel tijd krijgt om iets met een bal, of shuttle te doen. Sporten: tennis, bowlen, golfen, tafeltennis, squash, badminton. Jij wordt net zo goed als: Martin Verkerk."}
  },
  {
  {"nl", "Sportmascotte. Je zou zo graag een echte sportster worden, maar alles zit tegen. Je hebt het balgevoel van een vierkant, je bent zo stijf als een hark. Als je gaat hard- lopen, dan ben je na een paar minuten buiten adem, en in een snelle auto raak je meteen in paniek en sta je boven op de rem. Maar geen nood. Ook jij kunt succes hebben in volle sportstadions. Word mascotte van een ploeg! Je hoeft alleen een apenpakje aan te trekken. Met jouw gekluns, maak je de toeschouwers gegarandeerd aan het lachen. Sporten: mascotte Jij wordt net zo goed als: Dutchy de leeuw, de mascotte van het Nederlands Elftal."},
  {"en", "Sports mascot. You would so love to become a real sports star, but everything is against you. You have the ball feeling of a square, you are as stiff as a rake. If you go running hard, you are out of breath after a few minutes, and in a fast car you immediately panic and stand on top of the brakes. But don't worry. You too can have success in packed sports stadiums. Become a team's mascot! All you have to do is put on a monkey suit. With your fumbling, you're guaranteed to make the spectators laugh. Sports: mascot You will become as good as: Dutchy the lion, the mascot of the Dutch national team."}
  }

};
  
void printq(string l,string q) {
  cout << vragen[l][q] << " (" << antwoorden[l]["c"] << "/" << antwoorden[l]["d"] << "): "<< endl;
}

void printa(string l,int a) {
  cout << adviezen[a][l] << endl;
}

int main() {
  for (int i = 0; i < talen.size(); i++) {
    cout << eerste_vraag[i] << " " << talen[i] << endl;
  }
  string taal;
  cin >> taal;
  printq(taal, "q1");
  string answer;
  cin >> answer;
  if (answer == antwoorden[taal]["c"]) {
    cout << vragen[taal]["q3"] << endl;
    cin >> answer;
    if (answer == antwoorden[taal]["c"]) {
      cout << vragen[taal]["q14"] << endl;
      cin >> answer;
      if (answer == antwoorden[taal]["c"]) {
        cout << vragen[taal]["q15"] << endl;
        cin >> answer;
        if (answer == antwoorden[taal]["c"]) {
          cout << vragen[taal]["q16"] << endl;
          cin >> answer;
          if (answer == antwoorden[taal]["c"]) {
            cout << adviezen[taal];
          }
        }
      } 
    }
  } else if (answer == antwoorden[taal][answer]) {
    cout << vragen[taal]["q3"] << endl;
    cin >> answer;
  }
return 0;
}
