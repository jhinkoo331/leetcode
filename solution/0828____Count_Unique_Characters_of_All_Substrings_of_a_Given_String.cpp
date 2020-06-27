#include <string>
#include <cstring>
#include <vector>
#include <unordered_set>
using std::unordered_set;
using std::vector;
using std::string;

class Solution {
public:
	int uniqueLetterString(string s) {
		return _1(s);
	}
private:
	const int div = 1e9 + 7;
	/**
	 * @brief Time Limit Exceeded
	 * 
	 * @param s 
	 * @return int 
	 */
	int _1(string s){
		//* current length of substring
		int len = 0;
		//* count of every char in substring
		vector<int> t(128, 0);
		//* count of distinct chars in substring
		int count = 0;
		//* the answer
		int ans = 0;
		while(len != s.size()){
			//* expand the window by 1
			if(t[s[len]] == 0)
				++count;
			else if(t[s[len]] == 1)
				--count;
			++t[s[len]];
			++len;
			ans += count;
			//* shift the window
			int ll = 0, rr = len;
			vector<int> temp(t);
			int temp_count = count;
			while(rr < s.size()){
				//* update count of distinct chars
				if(temp[s[rr]] == 0)
					++temp_count;
				else if(temp[s[rr]] == 1)
					--temp_count;
				++temp[s[rr]];
				++rr;

				--temp[s[ll]];
				if(temp[s[ll]] == 0)
					--temp_count;
				else if(temp[s[ll]] == 1)
					 ++temp_count;
				++ll;
				ans += temp_count;
				if(ans > div)
					ans -= div;
			}
		}
		return ans;
	}
};

int main(){
	Solution sln;
	string s = "WEVNOCCPTSKWHGNKXTUAHWERFVQGPAQUHGUSUITSYRIZGBQUXDASQPHHCPOLXJTJPSTJWIVSNDESXBYLRZXXMKKKLZEDPDXXRWTVSDDPXHIBURSHWWUVZMSDCPKLUWTYBYVHDRSRQIKLHZGXBETNGRALRWONWZOEORQLRQZYQHDFKTJEUOJXCHQQVBIYKIKCBOEOOKKOTOHLOYHOUTIQXALOKSSJBBBQXYQTOUCHHZWCLCYGWFZVABJLVGXGHPTXSIDMAZUISNEZWBSJPQGVRSBTPUAFFQBXPKFCSTETFGQKMDHJWQSMVYYQERNLWRWNIDZMFTKUZCPBGAWAVXYHAKCQDFYPLIZFKRIPWHSSSQWUKEFTLPNQFCRLYCYGOZBWXPDSUCYZMDCWHHNZDGRSRRNNBEOQCYQAVFGQFCXCOQQLZUKXUOPBEPBNQXIGIXWYKUIPSPZDNUVZQEUVWLAUXTGOWJYRTRLOLUODWZJJBEESAUKDDKDMKIFNVYYJGDRJHZBAKMWAOVOCQXALSALYVNINYAGMGHYATSWMGDMICPGAEJPIQQZZOTIINWTQCWLEGXRDMFQJVFLNKENDDTOIALDWLGLOFHRUYOTNCVKCFJOQZZAKYJXBKXKTXTMOUDJKAESQOCYEDUYEXNUKVJPDTFCEWWOTQTGLKHUUEASNKDAWWNJPVTPTAOTNYZWCUCTZCCIHTRQZFKVDVFRXKYILHSQUTHYKYEELRRCLIAXPSLWCIPAYKZDBBIYRBEKHMFCNGNOCLMSFOWDOIIUDAYRQUOFSZZTEVHRWELDBIVYWDYXAKAIORSDYQJRAUQFLBWQYLUEHEFQFQGPIYHXPKXARFJEWUKLOXRFHZUYNOZEYRPGOPPFAYOEKYBJXIPEFHMPVDOVIYREIYGQUQUNOVLWNCKQARQWEOURFCKGBJEJEHULFGZJSUJTKZJMGWYCSXZETHYRWKWVJXSPXIHQCXAXEHBSPFTTYLCPYWCLJDORCEMAYZDIGSUHUBSUQDZVRGXBFSLYWTYKRDNMMEDJVUPBFVUVIJYONGADBLXZAMNPFTAEHGHSZMGSRDYNLPTGCAAPWEZVXPPIPCJFKIJYXJRTOECQCONURCOKAPSXWUTEKEDSPMPMYIAZQSXWDUJNZEWCEIZPZOCVCXJAVQMPNXVNCFXELZKBSPABACUHGOSWPYOFOGQKULZCXGSTAFEIPKVDRVOYMDWPGROBLPZIDPVYTFCAVHKUMTKDDNGFSJRTUXWPTVAJXQOOITLAKAJUKCJVGJIHGRCUPBESKVVNCAVXBLKGRGVDFRUVKDMIPYQDKXWVKSJGCQHXYCSKLUSPNDAGSTYXJJTIHIRWNIHYIXDOCYAFLWYNYSFOBLDHUIRQGRRWHOLWSBFJENNJVGSSTYQNYLEGTLBXCKQQPPHWLDWZDNAWTXASKWWSGXRKYBWIXAMWNWZBITVVSTUTLAWTDFJEPUGTNLULWNKCBRUDNWQMAGNRIVTZCTXZKRTASWFRLNUVUGUZPUKZGGLWPUQXGKMEWOBLTJIRSXHVKWGKNUTJJFWCZAXAKKVXAVVHYYLYLULRYBSWRKUZRDZQMQGXGQSYSJTOHFKFBLZAJYGXYXGQTBJEYYNKRFCADFIGVYDYLURCSSBIRTFLKXURLLPJLQYTFZGEHDLMJDYJWOEKXYWOATDMQKRDFCSXFQEMBMUQHSUBBQLMBHOHMFIDCLURHFKRHAQRGHUKYMELQGDEGLPKFADXEPVKUGZNTNUXPWRMJZGWMFAUXGYMTKJBBINTYUNVMCFOQNLBUNEEVFYQASSYDBQWPMMVAWGCSKTYQUMKMSFEBBAJAEKUFOMUFEPZVZNILAPTMPGTGWZGVBGMWMRKSNQSLWDIRNWSFVIFIXFEZSMUOVIKMRCFXPTLXJNFFDYWJZRMTVVAODMHEJBTUPMFDSJFMXKPYTWABLKZNQXPDJNGRYKPPIVKJRBWWMQPQCLXBNUFALTKSIMOTDDAJIMGYRLPPJEKFKBANCMLXTGVBKUQVVEKUNTPXNYNOQLRDCXWXCMGZWTYGTCAPJGHSNTQUMTKFWOWHXQBJALFYQBIWARUAWKOFRJDYPVTXKNWRHEKZYJGHBTTXZBLGNTVKEWFXGZLLCHZSGDYQFOADZHSBMBHTXCGTQJQKXOUHGKCXVGLHSJSVIGRTNJVRIFUECWWASLZCSCYCEUEJRETYXSFKLYBMDJBXJVQERHOSWTBJHJPJRRNVWKCQWMEZURSMRYKBVINGXZLIJEUIOPTZZYUXDDZFRMFHPAXFLTRXCSLUQPSHGZUVJNOYQYJYCLGJUWJHYTEGPDGKOXJUBOIRZBGCDSQRETGXRGABOIJDLABYKCHIJRBUKUOZWMPLVRJQOVTHFMEHFLKXKONFNEYFHKPHOCOTAAAKFAOQQLLFFPRETRPNDTPNRNMEHJKAEMHLPDIQEJAYWXCLKJLQBGGFNYPKRVMMXGWOFBJYDLIQWVNWFCIHTKTDFONQXTIRAWITYBKKMLXWGJMSHVQGLLCOVOVYQBAZSYPPRHERAERZCNAZDZMJZSECTHXGUDNYXTVNEIVQRKCXZSTJOTVMEPARRWEIFQMRTJVOEMEALQUUQEXEULVWGXMYFRXKAHLTKEHHGBGRKGTDDMVEDBROLHTMQLKNBMFAOKBIQOJJHZOWNIZGWKVKGSCMTOXMXWYINNUGTKFOTOIXBDUYMZUKEYWRVLXMUKLOLYULFCYCANYILLYPJUFJFMLWKATMAAIHLCSRKLAARSEJMGYLENTWCVOORPAOAWPCZIJVSRERDPGNGVHUAFHWKCYWSVFTQBGYEVWBJVGCPWBYZYMVKKHRBZIERGZEREGJZCAJHDNQBGQWREJKQFQAXHCJYLYLVINWBEUYMKBTSTBOAVWNCONJZGHQSSXABEIAKWEZPCKETIFGOTSQSADJDPRFCILBTTFVCJGWVZZBJNINBNZTCOLDBYRUHENVSVKCJGITSHERZQZCLEQNSPTWRRLPDRQYMFOVMZIJNTKEGNMYKPOQBMCGGOTZAEEWTNLSUGSTGFVYWPQCJLUIKMXUITCYTTHPKEOHILHFMGMGANQEAKFTIJSAVWLARJKNBOXYNGIZAPLNKKOGRLZBXFLYEAGDJEQCMTRYPDSJIFOWGVHWOJNRNZQTPJHIHIRQGKBFSSFOWWKLSJEYQFLVMQEVLCCBYPWIVATQHLUEXOQNDAATIMLIGDFQSWVVPQOFQWJWKQMUWAJJRAKZEHQKWSCUASZLPXNYPCLJGADGOULHGPMIUIRTQFNPBPBISLGCJCSOBZPNQJJAAZZXYZQEYPUHXCDWYZMZOXFYCNDPJEZJBNHLBKRWJGBVXCYVSKZYVMMYJKNUNUMAGIGAUXQDYZTSPKTZAUROFCYAFDKTUEQRKIVBSNDZEOENKUZONYXIXOMCZNRFURVYLWWLLCJQUQFNDTVJBSAHRBAXXVTFKHSVLKGUNKHZGZORALKSRRNYSLZDYNQXMGCPGKYLXHASQKDMOBFNVQZUMZIZEGTTIMXCFVGHNLGBQLNAOSAAAOAVBDEJIFHVUWDDHYFDUCQDEDYAHXILGHJYTMGPFDTJQNCQYQZWBWPLQPMNJMDPRPBWJZUHCOYVSNTUXLQCCOLRGXZULSMZHGVIHDIAUVZAZPYGYMMPTOXURVEEKTWERULAIETFSBQCYMHKFHIBIJFFZCOYRKSRDHEVTAUVXXQGPBKQVRJJEGKCXJTVDCZKLUGWOPNWHWTFXXRZDRYSTIYFXYIAHDEZIVCWSOIOFKGWFUQGXWIKKXZUCVAKGWEJTOQRPQZRZGOJOVQTJKVFVOUHBDBIUNWJRAAFAVEXQWWAISLQIDCYOUTPMBBJXWNICJUFHDRJZOGDEXHVNTDYPDBHRPCRVPIITUYLZLRPKSUTCKMXSXAKYBEXKXHLCVEHXNNBZOXRVWGJOTFZQZZRMZKNFOWANLFZCRQLWSDAKQEQJGKKZNJDQZUWRBVBRTXKJOZFBSDZENXGZRKPAOFTJAEZTWVXZDFTRRXXUURPCSKHQDXKZTIJJUXIVMEXCYQOKQQVBFZUAYWTFNLWZPMFPRCNRYDFSNMNVFOHPJMVBJPXYJPBKJEFGOGWHPPUBAXVGPOFRQFYNZYHVYOUWLAKXAAFTNZYKRSAAPYRLTCMPEBQETNYAQGLRGSQDMZPBSCFKCZMHXXDGDDLKIBILGTHXDJHDGZLDQTNUNJNLHZZEPDOQHMOCIKDSKXGXXJFYYRZGIHANZYAPZIERLTHXKMXMFKTCRFWYMDJVMFJHGZHEKVQCELFTNHYOGETOHSADQPCYDIIPWLKHZTJROPJKFBICWSKXVXQEZZDTKDZEREGTLCQVJYMWEPDLYCJPLQFNAUQNJEHXNGSRAFICDHFWUHWZTJRWUCWGNQVGWIGDGTJKZCGLZCOXXJXTYQVLODFTMMALTKDFFQAHEBNFDEFIURXCTUHZHARDKXUGVUFRLDQORAJKITSYMQDDXVBNNHVGMWBDVYOABFWQEXJDRZIMTLAEJILMWFBETZTVJGZKTUFYYXHURSLUUXLUOUIDVLHPJYCAZPPIULSKIBPCEIAAWLYBGPQQJWVHAWORVALDKDZRDGOERTQBPRPHSQPWOIKDNJZXTJUPLUKSLXMMWZGSAWZBMYMIROAARVRKUVCNARWBCYVBAENMBLGDXGWPKNZJFTDOWGPOGAYHZLQMEMFRPLDQBRENOEXHBHMPNDMJITLMMHXNBNECMUTWQZSBLBNSAIMQQNZGUBSFTXXZAGMRBOLSWJDXNGLEVZYWKMKZOECJKIMRWGGAKOTEQUOVRXIJKFOCOFSSIKIQTKDIYJYFPPKPSQUYOTSXXOELEOXYLDRSNLJHUDORYUQNNIOSADIBTEQSJPULVRIJBKFJCZYWVFQWONDZKISFYZANAXLMMZZGEGCMDVCPUJQQDGCJGKZIWQWRBENXCVUCECWVEPYTQOCTKWFZWOAUXOPKGLAEZOLPVLTSQZDTRCLDKLRVHAOBRQSZIWYKADFFVVUGVYSXSKCJOEVHYEGLYDBAEBTTZGPLYFDBWHYPLUWOMBIKSVKODWCOTSZUSBKYQFUPAROJNTKBAUROALBCRIBKWCTIHAOGTXKTDIELZHKVCTKIEWHEIHBYLHXYFWGOSPHBVGTKSXPCLCTIZUKTYODDEGFBLOATOAURBCXDVORQEZDWDBFMDVDKHZYHBSZAKBYDKWZWEJGQNRIQIFTILKXALOGMNKLZOTFFGOASZAPEYMFWCMDJGOEXIFPONHFOUHIJMDYYZFFXACDSRZUIJQYDMHDHSOPCIVGFGRUARODOFULYQLZMCYVCYQWNJSUIEKDEDHUOSQQPQUAJNWAADKRIFLXSBIOPORJVXAAWNKFNSOTPPBMSFHORJNUUOCXZSVSTCICKXGQVZOBLQRKCCEFSRLIHMFFMLAZUAVLIYAHMVTJMUPLKBPOFORWXVOGEHEQDCQPAYBTTXETVJVTUXSGSRJJPROCBTGEHLKPAVDTYZTEQJYVLLZTKWRWUDIQIVRVYABKKLLRRKHPZQPPYCVLHOHVFNVZBXPSVVTJIWWMYVEIUNJROGFRUZPPHTIEKFAOAMTLKSEKTWKUJLILQCUFUAXCMQJLAAFQRNFMXCDAETWKFQKNHOPOFVDJNDKXOPFFYYSDLRDGRONVYGOKNBEPVLYHUSWUMCQMVHXXHOITPOIJDGZQLLFHPYEASXFZOHRGIZIYODCJXKKIMVBYOXZVOUYLXXRSMGGEZANWSHXVVENHYRQNJQTZDYIKBSYEAAKFTHDJMXZJZVDSEZJXZDJDXEIPXPBTOLLGNBUWJCDJYXJTBQLTAWPALHXYVZDVGGABJWAHCUQJEVLNRTYAZNKUBTFLXRJETQBXKFOGBVQRTCWHBASKSXUSYGDQLEMVQDSJNTHUZDMMNCVWSDRZPFKAYYOCLBVTQSTVBOBTWDUPIVIFXFMUAXWLOYPIQIIGOHPIFQLNTDHUUEBLRMDBOPEETWLSLVWPWJIZDCIBNRMRPPAMUXOIPKNTOMCBIOVAKWDHEKRWKGIPDGDCJLPVIJZOPTBBLYXEAMJEPJNACPTPDPRXRBLTDKTTCWTISUPCEZSMZNBBBQXKOHNYWEOHJSUUUTBYKGGHIUSPULYMWIBYNQEHACCAQLLGHCQEVNQYGQVXZLFVKQBWFDUZUDQAGMNLWCGQHQCFXKGIEUFUMAKNYEMOMONYSCUBUKRQXRTMOEBYWNBNRWDKBDZVJWYFLBPAVYAEBWWWZZPERYVEGHZZZPFDKROFJBKJTAOYTBVPCISUFTZGHCQEYJSFGBNGDKRIPLLZCZRGVIWSMBMYDQRIILCJQLKMORYRMOCNWQWSZXGGAMRKKJLASROIDJBKTPBJVPLEVOAUZPZWCGSXJPNSEHBAFVUUBPTGPHEBHAAYXIMEURDGKQEWXUMMCAIBAQLZPQVAJVIEXEDWZBCOCMIQNXNUZVXVYAWHNKXROZMSWSYOQBUBYYULBVEGPTCXFXCTVJIFZDQMTBMNJWMCQPTXCQCROVZSXOGKYLOMLTEQUOICSTLYJMYBQFGXPCFYWYHYZYBGZNGAUHZGSEFYPHSINBLXKGYBIQOETVPSIICUXNLTHHQRRSISPKJGIKSTNCUGRCRONSFLMBJOLMYPSFQHSCWIRFYPNGBKRWQKSNQEHJUFQAYULVMRVYQRMGFLUYTOHUEIQMTTCGCQRGHYKNWNRSZRBBTVCWUPFHMVWRMIQXMSLEYIHBIQTAEEEZYKXAILEWPYHCTTJULYESIIANHEWKUUVQJSZKRXEGUMYSBLKETIIZVPSBVXSVLHSTIMYYWLLSVEXDKBBIWSHXKPBJCDFCCYIWLCILHFMIRVQBLYDUKOWAAGKMULNKRTCMIBVWSZJZNXWIPBRPFSYCCTQJEGLCQTDONVSLDSBDCKKDRMIEMLJMCGFPGCVQILGQHXQOUNVAMLQYOMYTYZKLQSHFLBPAUEIFKENZSCYTGAQKNNEPEKETNIQQFSWLBJLIBDKEOGOXOEDPSCVCRSWJBITCFZVFJNRWJLAJOGKLVPMEYRJCLKAHNOSMWOZBZKGYTDAVDPCLEYYKJXSVUBDJFYXTTXKTTISBTRVDHBPCSVVBWNMILCECNLBNJJQEMUDIASNFJUSRTYXLVTASTVVGCBWNFTRQSIQVOIRFBUATUTAXSXLZMSRKYMMRHJUPPOVUJMHMCSCNPDIUJJTEAFUZLCFSRJVHKKZRUBMIFKGZDJGKJPTQCZRCIDLXIUQODKNVFJEACIOEODEWNCXTWAVBHJUDIQKXRLTRBMHFCQVSHYVQBUCFFCMVLOMFEKOIUCIBMFLEXPWQRJUQEYCQOHFDGFJGZIHMLOZCIRSTGLZNTKRAQOPPAYKCWAIAAJBAADPEMWGKGJBNJQYXBUVGGFQKXTQJMYQTEJUZEQYJSRUMYXORYGKFZLEQDDWNGRSTHTQDTRIYPTNZQXOADLLYPSVHYCEGGEOSOQLIJTBUYAMKBUBYIGFPYWDPLKSOTOWDMTVHDFKXADPKEQDRZTIRXJUREOGFWEPMOWYXIOMRPYEDLJLMFSZMVZTKJIOFNXEPJDIGVEJJNUHDMTXKSHNVFTSFXTQHCEXTTLUBSASRAPQFUMACVRWFAVEXMRCWSTLHCFZMIPHTVXRSSNOKFSVVVTBVTCKPEWSIKTJTYVWTWFHYVZDKEDFLCYTWDUQBBLJXACRRBDSFBZQKADHHYYWTLTMPPBWIMJOOIEKJOIZOLNRBZHGSFRCLDGBIKSPOOSXOUWIWLLEMMDBMNKKFIEMUADFASRRIGYLGACMBNHSPVWTSNHQUISKFTMPPVHYRNZNAENZSLBJLDSKJSIZCJANDZVLEMXIEDLEQFUZHXZAQTCZYEENYIJDOHJJQDVYCITZNFQYXOCRXGSPMXKGTICSQETVODNHZPVTUHYVEVNTBUGVGLXNPPRLWLSWIKANDWTFMKQPZPTSJFNJLFOYSWPTDEAEUQFIIHYNSYNFNLRTBMHAEWXOPFVNZRXRMUDXOCBVTDPDRZULDTVJBKERPQIXEESGRUENHKPMOYBHHLNGFMVCQRCRPDRFLMQXDUFVZSZIFUOUJQBQCYQRFTSIYUOLRPNMXMHFQHWZAIRFJHJFIKHWZKQXPTZMMJZPPFFPASUTKEEBYOUZLAMQBVXAJGSFHNOBDVLBFSFCDXCOFKXOVASAMCNDJCAXPNBOQJAQPYTZBTSMEURATZZWKLKEBKPOVQGXUYJEQYBGBDDHJQACAMWNRQYTZOMXXNEBZXERPZSLJIADESNJMTBDWJIQFTIUCFPEUUAPIPSUKKOXNBNBZTULTLUGULDNRACEQLJIPUASDJFETCYDZWGSWHDLGBRIEIMFOJPLVTTJMAVCPTTFBCVLHZUUTOACMMIHSIXKSQWVAGBEBNXIZCNZVWFVKNCDSYEBTHAMBPGSUHPSNDYHRGWJOYWSOCQPMCMHXRBMNLGRMEFYBWWOXGBTYVGCUVOEQRNUGRWNSJCCNMNZGDXLTXDXNYBZYJSLWHKAODREMXMBGFCBATFIJEYQOWKXZPXYGVIDJBZUDJRFNDJDRGQYSLHJWPOZNFFCBZMAODNVFYHRSPGUXOABBHJHECPEHCETVWANOTTMGIWQUQEVHVWHHKRUKNDXOJKQQMPDFBKREVLZDSWQMLBYTLSDZEEUPJUPFYYIEUUKHBXQLAFPJFDFLOUVRZSULIYKSGGEAIMLBLJUJHBUJQTXEBECNERMNBITSNFXWHPETAVVPNJFUFKJXEUTGZESBZEVJVIMQNDODMAGHORQFWLRSDMDNCHDGSYKMRPUACFWLIMSMXXHDRCWUEWUWTKBCUBIQILRROTENTFZLJEPLUZJPLQXNWOUCEHHMLMONTEWNLKMQLXMRMYIFBWXZSRVZOGEFOCORZENAHZHLEYXYRVLYGTXIQDLZNYTCKNTJEZQZTQNWKPZCUOGUXJVVQGIROCGKNQIDJZDCLKKBCNLIMOFAVAZNGOVVNQVCHMUFLWFVXKXUPLGZBGUVOAELEYGTWBJJDIQBRXZEIJORHGONUSWMRKYEYLFECFUMOZRWYGTBDNSLYLWAYAXEOIDVHDDFNZLRRYQINOMXPZZQEXFQGTCGIRJZPMCXYRQTVJLEDFGRQXSTKBUBLSAZOFVQLAMXBWDACEZLMPYXYSTMJLJMDEEHZTOGYTJUBTLZEVHHHNVSSERCALNXTHBXTHICYIUIILJZZNZHNJFMTCKTCWJHFQETDTIGDEENRQLCKTGYNWZWOUGJMEFJVEFFRYRLGFEFWPADZVOWIYTOMTDWGLIBMKOMQCUJWZTNRSLGESTVXWHQUWILCQMXFZQFGSVHWMKVIYMYFDUOLMUYUIRZDAOBIYPRMWUXJNYZDKRCWCZHRQOFSQKZHOEFIEMGMTGRNEKRRFSSBFHSDNQGCOWZUQFGRJJZEXTPDNPWIEPSOZSLGJRJDLINLIMJFNSCGLDVVNBYEKXCKWZGLLBJJPIJUVUIAKBZJDMODHQPXIPNPKVFQFULEICRINAWLXUESSDSDJFFVLUDOTTVJWZYCNKMTDYDXLCHDAISQHKWVMILCKSKXOIFYYIBKYGWHSMGZDPRERWAEMQVDHRICIOEWYCUOBBQZKDPPJAZCPXKQVIFFKHOJFVQVUNLBNFBTDETMFIHYNYTPRPMSFEVNWINYIYDFPQCKPKHLBIJAETNJELPZOJLIGBASBAFXUTUVRAKNCYFBHNSIWTYSHOVLWDCQYAYXNMZJCRECXADYRDDXPXJFMLCPPOZZYAHTUVWQHYEQGDWMLAMOIZMBRVEGWZIBJCRFBMUEFUZHGSYNLBUTFSYYCGTROLHUMFHBLLRKKGAVXGLBSOEFMVRDBMFVXJBWMLOMACGIFMFMALFQYKTICOUJSPXNOHOGCAUDBYVXBIBEAWICAQFZWPLXRZBECBRRQYWFMTBHSDHBRNVYFNMEIKJCM";
	sln.uniqueLetterString(s);
	sln.uniqueLetterString("ABC");
	
	return 0;

}