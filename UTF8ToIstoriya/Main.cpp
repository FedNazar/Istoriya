#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <codecvt>
#include <unordered_map>
#include <locale>
#include <io.h>
#include <fcntl.h>

std::unordered_map<wchar_t, std::wstring> istoriya_char_table =
{
	{L'А', L"Автокефальна церква - православна церква, яка має цілковиту самостійність у розв'язанні організаційних і культових питань."},
	{L'Б', L"Бандерівці - члени ОУН(Б), того її крила самостійників-державників, яке очолював Степан Бандера."},
	{L'В', L"Український визвольний рух - національно-визвольний рух на етнічних українських землях у 20-50-х рр. ХХ ст."},
	{L'Г', L"Генеральний секретаріат - виконавчий орган, створений за рішенням Малої Ради від 15 червня 1917 р."},
	{L'Ґ', L"Гласність - ліквідація цензури в СРСР М.Горбачовим, складова проголошеної ним програми реформ."},
	{L'Д', L"Дисидент - учасник руху, спрямованого проти комуністичного тоталітарного режиму."},
	{L'Е', L"Евакуація - організоване вивезення людей, підприємств, установ та матеріальних цінностей з небезпечної місцевості під час війни."},
	{L'Є', L"Євген Петрушевич - державний і політичний діяч, один із керівників Української революції 1917-1920 рр."},
	{L'Ж', L"Андрій Жук - громадський і політичний діяч, публіцист, кооператор, член РУП та УСДРП (1901-1911)."},
	{L'З', L"9 листопада 1918 р. - утворено Західноукраїнську Народну Республіку (ЗУНР)."},
	{L'И', L"Вільгельм Франц фон Габсбург-Лотаринген (Василь Вишиваний) - австрійський архікнязь, полковник Українських січових стрільців, поет."},
	{L'І', L"Іван Багряний - публіцист, письменник, політичний діяч. Належав до літературної організації письменників Києва «МАРС»."},
	{L'Ї', L"Українська Центральна Рада - провідник українського національно-визвольного руху."},
	{L'Й', L"Йосип Сліпий - митрополит Української греко-католицької церкви (3 1944 р.)."},
	{L'К', L"Курултай - орган громадського кримськотатарського національного руху, утворений 26 листопада (9 грудня) 1917 р."},
	{L'Л', L"Лібералізація (за «відлиги») - курс на пом'якшення політичного режиму."},
	{L'М', L"Мобілізація - комплекс заходів, спрямованих на переведення країни у воєнний стан."},
	{L'Н', L"Націонал-ухильництво - ідеологічний штамп, що вживався в агітаційно-пропагандистській роботі в СРСР."},
	{L'О', L"Олесь Гончар - письменник, громадський діяч, академік, автор трилогії «Прапороносці»."},
	{L'П', L"Помаранчева революція - сукупність протестів та інших актів громадянської непокори на підтримку Віктора Ющенка."},
	{L'Р', L"Русинство - соціально-політична течія, що виникла на Закарпатті й прихильники якої обстоювали ідею, слов'янське населення тут відмінне від українців."},
	{L'С', L"Соборність - ідея об'єднання в одне державне утворення всіх етнічно-історичних українських земель."},
	{L'Т', L"Тимчасово окупована територія - частина території України, яка контролюється росією."},
	{L'У', L"10 (23) червня 1917 р. - Перший Універсал Української Центральної Ради."},
	{L'Ф', L"Володимир Філатов - офтальмолог і хірург, засновник відомої офтальмологічної школи."},
	{L'Х', L"Холодноярська республіка - героїчна сторінка боротьби за незалежність України в 1919-1922 рр. Повстанський селянський рух здебільшого охоплював Чигиринський повіт Київської губернії."},
	{L'Ц', L"Олександр Богомолець - видатний учений-патофізіолог, державний і громадський діяч, організатор науки."},
	{L'Ч', L"Чортківська офензива - найуспішніша наступальна операція Української галицької армії, проведена 7-28 червня 1919 р."},
	{L'Ш', L"Шістдесятники - представники української літературно-мистецької та суспільно-політичної течій наприкінці 50-х - на початку 70-х рр. ХХ ст."},
	{L'Щ', L"Отаманщина - явище, що зародилося в Армії УНР наприкінці 1918 р. під час антигетьманського повстання."},
	{L'Ь', L"Тіньова економіка - господарська діяльність, яка відбувається поза офіційним (державним) обліком і контролем."},
	{L'Ю', L"Віктор Ющенко - Президент України (2005-2010)."},
	{L'Я', L"Ярослав Стецько - діяч українського національно-визвольного руху, член ОУН (з 1932 р.)."},
	{L'а', L"Автокефальна церква - православна церква, яка має цілковиту самостійність у розв'язанні організаційних і культових питань."},
	{L'б', L"Бандерівці - члени ОУН(Б), того її крила самостійників-державників, яке очолював Степан Бандера."},
	{L'в', L"Український визвольний рух - національно-визвольний рух на етнічних українських землях у 20-50-х рр. ХХ ст."},
	{L'г', L"Генеральний секретаріат - виконавчий орган, створений за рішенням Малої Ради від 15 червня 1917 р."},
	{L'ґ', L"Гласність - ліквідація цензури в СРСР М.Горбачовим, складова проголошеної ним програми реформ."},
	{L'д', L"Дисидент - учасник руху, спрямованого проти комуністичного тоталітарного режиму."},
	{L'е', L"Евакуація - організоване вивезення людей, підприємств, установ та матеріальних цінностей з небезпечної місцевості під час війни."},
	{L'є', L"Євген Петрушевич - державний і політичний діяч, один із керівників Української революції 1917-1920 рр."},
	{L'ж', L"Андрій Жук - громадський і політичний діяч, публіцист, кооператор, член РУП та УСДРП (1901-1911)."},
	{L'з', L"9 листопада 1918 р. - утворено Західноукраїнську Народну Республіку (ЗУНР)."},
	{L'и', L"Вільгельм Франц фон Габсбург-Лотаринген (Василь Вишиваний) - австрійський архікнязь, полковник Українських січових стрільців, поет."},
	{L'і', L"Іван Багряний - публіцист, письменник, політичний діяч. Належав до літературної організації письменників Києва «МАРС»."},
	{L'ї', L"Українська Центральна Рада - провідник українського національно-визвольного руху."},
	{L'й', L"Йосип Сліпий - митрополит Української греко-католицької церкви (3 1944 р.)."},
	{L'к', L"Курултай - орган громадського кримськотатарського національного руху, утворений 26 листопада (9 грудня) 1917 р."},
	{L'л', L"Лібералізація (за «відлиги») - курс на пом'якшення політичного режиму."},
	{L'м', L"Мобілізація - комплекс заходів, спрямованих на переведення країни у воєнний стан."},
	{L'н', L"Націонал-ухильництво - ідеологічний штамп, що вживався в агітаційно-пропагандистській роботі в СРСР."},
	{L'о', L"Олесь Гончар - письменник, громадський діяч, академік, автор трилогії «Прапороносці»."},
	{L'п', L"Помаранчева революція - сукупність протестів та інших актів громадянської непокори на підтримку Віктора Ющенка."},
	{L'р', L"Русинство - соціально-політична течія, що виникла на Закарпатті й прихильники якої обстоювали ідею, слов'янське населення тут відмінне від українців."},
	{L'с', L"Соборність - ідея об'єднання в одне державне утворення всіх етнічно-історичних українських земель."},
	{L'т', L"Тимчасово окупована територія - частина території України, яка контролюється росією."},
	{L'у', L"10 (23) червня 1917 р. - Перший Універсал Української Центральної Ради."},
	{L'ф', L"Володимир Філатов - офтальмолог і хірург, засновник відомої офтальмологічної школи."},
	{L'х', L"Холодноярська республіка - героїчна сторінка боротьби за незалежність України в 1919-1922 рр. Повстанський селянський рух здебільшого охоплював Чигиринський повіт Київської губернії."},
	{L'ц', L"Олександр Богомолець - видатний учений-патофізіолог, державний і громадський діяч, організатор науки."},
	{L'ч', L"Чортківська офензива - найуспішніша наступальна операція Української галицької армії, проведена 7-28 червня 1919 р."},
	{L'ш', L"Шістдесятники - представники української літературно-мистецької та суспільно-політичної течій наприкінці 50-х - на початку 70-х рр. ХХ ст."},
	{L'щ', L"Отаманщина - явище, що зародилося в Армії УНР наприкінці 1918 р. під час антигетьманського повстання."},
	{L'ь', L"Тіньова економіка - господарська діяльність, яка відбувається поза офіційним (державним) обліком і контролем."},
	{L'ю', L"Віктор Ющенко - Президент України (2005-2010)."},
	{L'я', L"Ярослав Стецько - діяч українського національно-визвольного руху, член ОУН (з 1932 р.)."},
	{L' ', L"Вересень 2014 р., лютий 2015 р. - Мінські угоди."},
	{L'(', L"Грудень 1919 р. - травень 1920 р. - Перший зимовий похід Армії УНР."},
	{L')', L"Листопад 1921 р. - Другий зимовий похід Армії УНР."},
	{L':', L"Михайло Волобуєв - вчений-економіст, автор статті «До проблеми української економіки (1928)»."},
	{L',', L"Самвидав - тексти, виготовлені й поширені з метою висловлення протесту проти придушення свободи слова радянською владою."},
	{L';', L"Тамвидав - видання книги вітчизняного автора за кордоном, переважно в радянські часи."},
	{L'-', L"Експропріація - примусове відчуження приватної власності."},
	{L'.', L"Корупція - негативне суспільне явище, яке проявляється у злочинному використанні громадськими і політичними діячами їхніх прав для особистого збагачення."},
	{L'`', L"В'ячеслав Чорновіл - учасник дисидентського руху із середини 60-х років ХХ ст."},
	{L'!', L"24 серпня 1991 р. - ухвалення Акта проголошення незалежності України."},
	{L'?', L"3 (16) липня 1917 р. - Другий Універсал Української Центральної Ради."},
	{L'*', L"«Червоний терор» - заходи насильства, що їх вживали більшовики проти широких соціальних груп."},
	{L'+', L"Під час індустріалізації в Україні було побудовано 12 промислових гігантів."},
	{L'=', L"22 січня 1919 р. - проголошення Акта Злуки УНР і ЗУНР."},
	{L'₴', L"Вересень 1996 р. - в обіг запроваджено гривню."},
	{L'%', L"Середньорічні темпи зростання капіталовкладень у народне господарство України знизилися 3 6,8% до 6,4% у 9-ій п`ятирічці."},
	{L'№', L"2004 р. Янукович отримав курячим яйцем по морді."},
	{L'"', L"1970-1972 рр. - вихід друком самвидавного «Українського вісника»."},
	{L'/', L"Реабілітація - поновлення доброго імені, репутації несправедливо звинуваченої людини."},
	{L'\x005C', L"Політичною реабілітацією вважають винесення виправдовувального вироку під час перегляду справи із безпідставними звинуваченнями."}, // Зворотня похила риска
	{L'|', L"Першим судовим процесом проти української гуманітарної інтелігенції став розгляд справи «Спілки визволення України» (1930)."},
	{L'█', L"Казимир Малевич - український художник-авангардист, один із фундаторів кубофутуризму."},
	{L'▓', L"Колективізація сільського господарства - процес докорінної перебудови аграрного сектора, ініційований більшовиками наприкінці 20-х років ХХ ст."},
	{L'0', L"16 липня 1990 р. - ухвалення Декларації про державний сувернітет України."},
	{L'1', L"Леонід Кравчук - Перший Президент України (1991-1994)."},
	{L'2', L"Грудень 1942 р. - початок вигнання німецьких окупантів із території України."},
	{L'3', L"1923 р. - саморозпуск уряду ЗУНР."},
	{L'4', L"1914 р. - Галицька битва."},
	{L'5', L"1915 р. - утворення Загальної Української Ради (ЗУР)."},
	{L'6', L"28 червня 1996 р. - ухвалення Конституції України."},
	{L'7', L"17 вересня 1939 р. - вторгнення червоної армії на територію Західної України."},
	{L'8', L"2008 р. - вступ України до Світової організації торгівлі (СОТ)."},
	{L'9', L"1959 р. - утворення Української робітничо-селянської спілки."},
	{L'\n', L"Жовтень 1990 р. - Революція на граніті."}
};

int main(int argc, char* argv[])
{
	_setmode(_fileno(stdout), _O_WTEXT);
	_setmode(_fileno(stdin), _O_WTEXT);

	std::setlocale(LC_ALL, "ukrainian");

	std::wcout << L"UTF8ToIstoriya\n(C) 2022 Назар Федоренко\n\n";

	if (argc == 1)
	{
		std::wcout
			<< L"Конвертує текстові файли UTF-8 в Istoriya-код.\n"
			<< L"Використання: UTF8ToIstoriya [input filename] [output filename]\n";
		return 0;
	}

	std::wifstream input;
	input.open(argv[1]);
	input.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));

	std::wstringstream strStream;
	std::wstring data;
	strStream << input.rdbuf();
	data = strStream.str();

	input.close();

	std::wofstream output;
	output.open(argv[2]);
	output.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));

	std::wcout << L"Конвертування...\n";

	for (auto& curChar : data)
	{
		output << istoriya_char_table[curChar] << L'\n';
	}

	output.close();

	std::wcout << L"Готово!\n";
	return 1;
}