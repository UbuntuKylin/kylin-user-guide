require.config({
   paths: {
     "marked": "lib/node_modules/marked/marked.min",
   }
 });
require(['marked'], function (markedSetCustom){

//    alert('add marked');
    var marked = require('marked');
    marked.setOptions({
        renderer: new marked.Renderer(),
        gfm: true,
        tables: true,
        breaks: false,
        pedantic: false,
        sanitize: false,
        smartLists: true,
        smartypants: false
    });

    console.log(marked('I am using __markdown__.'));
 });

//readFile = function (fileName, callback) {
//  var xhr = new XMLHttpRequest();
//  xhr.open('GET', fileName);
//  xhr.onload = function () {
//    if (xhr.responseText != '') {
//      callback(xhr.responseText);
//    }
//  };
//  xhr.send();
//};

function qt_jumpApp(appName)
{
    onclickButton(appName)
}

var date ={
    kylinOS:"2019年12月18日",
    ukui:"2019年11月13日",
    kydroid2:"2019年11月13日",
    kylin_control_center : "2019年11月13日",
    biometric_manager : "2020年3月13日",
    hot_key:"2019年11月13日",
    caja:"2019年11月13日",
    ubuntu_kylin_software_center:"2019年11月13日", 
    kylin_video:"2019年11月13日",
    brasero:"2019年11月13日",
    youker_assistant:"2019年11月13日",
    kylin_ipmsg:"2019年11月13日",
    kysec_ui_pkexec:"2019年11月13日",
    kybackup:"2019年11月13日",
    audacious:"2019年11月13日",
    eom :"2019年11月13日",
    kylin_update_manager:"2019年11月13日",
    remmina:"2019年11月13日",
    vino_preferences:"2019年11月13日",
    claws_mail:"2019年11月13日",
    system_config_printer:"2019年11月13日",
    simple_scan:"2019年11月13日",
    mate_system_monitor:"2019年11月13日",
    gparted:"2019年11月13日",
    engrampa:"2019年11月13日",
    audio_recorder:"2019年11月13日",
    mate_terminal:"2019年11月13日",
    tools:"2020年3月13日",
    technical_assistance:"2019年3月12日",
};

function onclickButton(str)
{
//    alert(str)
    //console.log(str+"======"+window.pageYOffset);
    document.getElementById("mainUI").style.display="none";
    document.getElementById("pageContent").style.display="inline";

    var mdPath = window.guideWebkit.js_getIndexMdFilePath(str)
    var mdDate = window.guideWebkit.js_getIndexMdFileContent(mdPath)
//    alert(mdDate)
    var m2ht = getDocTop(mdPath,mdDate)
    var html = m2ht.html
    var hlist = m2ht.hlist
    var info = m2ht.info
    console.log(html);
    console.log("--------------------------------------hlist");
    console.log(hlist);
    console.log("--------------------------------------info");
    console.log(info);
    var hlist_str = "";
    for (i = 0; i < hlist.length; i++) {
        /*name_text=hlist[i].text.slice(hlist[i].text.indexOf(" "),hlist[i].text.length);
        console.log(hlist[i].type+"======"+name_text);
        if(hlist[i].type == "h1")
            hlist_str +=  "<h1>\n" + "<a id=" + "list_"+hlist[i].id + " href=\'#" +hlist[i].id + "\'>" + name_text + "</a> \n</h1>" ;
        else if(hlist[i].type == "h2")
            hlist_str +=  "<h2>\n" + "<a id=" + "list_"+hlist[i].id + " href=\'#" +hlist[i].id + "\'>" + name_text + "</a> \n</h2>" ;
        else if(hlist[i].type == "h3")
        {
            hlist_str +=  "<h3>\n" + "<a id=" + "list_"+hlist[i].id + " href=\'#" +hlist[i].id + "\'>" + name_text + "</a> \n</h3>" ;
            console.log(hlist_str);
        }*/
        var pattren=/[0-9]/;
        var name_text= "";
        for( j=0;j<hlist[i].text.length;j++)
        {
            if(hlist[i].text[j] != "."&&!pattren.test(hlist[i].text[j]))
            {
                name_text+=hlist[i].text[j];
            }
        }
        console.log(hlist[i].type+"======"+name_text);
        if(hlist[i].type == "h1")
            hlist_str +=  "<dt>\n" + "<a class='name1' id=" + "list_"+hlist[i].id + " href=\'#" +hlist[i].id + "\'>" + name_text + "</a> \n</dt>" ;
        else if(hlist[i].type == "h2")
            if(name_text.length >12 )
            {
                hlist_str +=  "<dt>\n" + "<a class='name2' style='line-height:20px;' onclick=onclickA('list_"+hlist[i].id+"')"+" id=" + "list_"+hlist[i].id + " href=\'#" +hlist[i].id + "\'>" + name_text + "</a> \n</dt>" ;
            }
            else
            {
                hlist_str +=  "<dt>\n" + "<a class='name2'  onclick=onclickA('list_"+hlist[i].id+"')"+" id=" + "list_"+hlist[i].id + " href=\'#" +hlist[i].id + "\'>" + name_text + "</a> \n</dt>" ;
            }
        else if(hlist[i].type == "h3")
        {
            console.log(name_text.length);
            if(name_text.length >12)
            {
                hlist_str +=  "<dt>\n" + "<a class='name3' style='line-height:20px;' onclick=onclickA('list_"+hlist[i].id+"')"+" id=" + "list_"+hlist[i].id + " href=\'#" +hlist[i].id + "\'>" + name_text + "</a> \n</dt>" ;
            }
            else
            {
                hlist_str +=  "<dt>\n" + "<a class='name3' onclick=onclickA('list_"+hlist[i].id+"')"+" id=" + "list_"+hlist[i].id + " href=\'#" +hlist[i].id + "\'>" + name_text + "</a> \n</dt>" ;
            }
            console.log(hlist_str);
        }   
     }
     hlist_str = "<dl>" + hlist_str + "</dl>";
 //   console.log(hlist_str);

    str_name = str.replace(/-/g,"_");
    //console.log(str+"=============="+str_name+"======="+date[str_name]);
    html_new = "<h1><a name='paga_top'>"+info.title+"</a></h1>"
                                +"<p  class='date' style='text-indent: 0px;'>更新时间："
                                +date[str_name]
                                +"</p>"
                                +"<HR style='margin-bottom: 34px;margin-top: 10px'>"
                                +html
                                +"<HR style='margin-top: 20px'>"
                                +"<div class='paga_top' >"
                                +"<img src='file:////usr/share/kylin-user-guide/data/icon返回顶部.png' "+"/>"
                                +"<a style='text-decoration: none;' onclick=onclickA('') href='#paga_top'>返回顶部</a>"
                                +"</div>"

    document.getElementById("hlist").innerHTML = hlist_str
    document.getElementById("content").scrollTop = 0;
    document.getElementById("content").innerHTML = html_new
    

}

function goBackMainUI()
{
    //alert(str)
    //console.log(str)
    //document.getElementById("mainUI").style.display="inline";
    //document.getElementById("pageContent").style.display="none";
    window.location.href="index.html"
}

var old_str="";
function onclickA(str)
{
     console.log(old_str,str) 
     if(old_str != "")
     {
        document.getElementById(old_str).style.backgroundColor="rgb(231,231,231)" 
        document.getElementById(old_str).style.color="black"
     }
     if(str != "")
     {
        document.getElementById(str).style.backgroundColor="#3D6BE5"
        document.getElementById(str).style.color="white"
        old_str = str
    }
    if(str == "")
    {
        document.getElementById("hlist").scrollTop = 0;
    }
}

function getDocTop(mdFile, mdData) {
    var hlist = [];
    var info = {};
    var html = '';

    var path = mdFile.slice(0, mdFile.lastIndexOf('/') + 1);
    var count = 0;
    var renderer = new marked.Renderer();
    renderer.heading = function (text, level){
        var id = 'h' + count;
        count++;
        if (level == 1) {
            var title = text.split('|')[0];
            var logo = text.split('|')[1];
            logo = path + logo;
            console.log(logo);
            info = { "title":title, "logo":logo };
            return "";
        }
        if (level == 2) {
            text = text.split('|')[0];
            console.log(text);
        }
        var type = 'h' + level;
        if (level == 2 || level == 3) {
            hlist.push({ "id":id, "text":text, "type":type });
            console.log(id);
            console.log(text);
            console.log(type);
        }
            return "<"+ type + " id="+   id + " text=" +text + ">" + text + "</"+ type + ">\n";
    };

    renderer.image = function(href, title, text){
        var hrefX2 = href;
    console.log(hrefX2);
        if (devicePixelRatio >= 1.5 && href.indexOf('.svg') == -1) {
            var path = href.split('.');
            var ext = path.pop();
//            hrefX2 = `${path.join('.')}x2.${ext}`;
            hrefX2 =  path.join('.')+ "x2." + ext;
        }
        if (text == "")
//            return `<img src="${hrefX2}" data-src="${href}" alt="${text}" />`;
            return '<img src=\"' + hrefX2 + '\" data-src=\"'+ href + '\" alt=' + text +  '/>';
        else{
            if(text.lastIndexOf("-big") < 0 ){
//                return `<h5  style="text-align: center;"><img src="${hrefX2}" data-src="${href}" alt="${text}" /><br>${text}</h5>`;
                return '<h5  style="text-align: center;"><img src=\"' + hrefX2 + '\" data-src=\"' + href + '\" alt=' + text + '/><br> ' + text + '</h5>';
            }
            else{
                text1=text.slice(0,text.lastIndexOf("-big"))
//路径需要用双引号，单引号无法解析相对路径
//                return `<h5 style="text-align: center;"><img  style="height:98%;width:98%;" src="${hrefX2}" data-src="${href}" alt="${text}" /><br>${text1}</h5>`;
                return '<h5 style="text-align: center;"><img  style="height:98%;width:98%;" src=\"' + hrefX2 + '\" data-src=\"' + href + '\" alt='+ text +'/><br>' + text1 + '</h5>';
            }
        }
    };
    renderer.table = function(header,body){
        console.log(header,body)
        if (body) body = '<tbody>' + body + '</tbody>';
        return '<div align="center"><table border=black cellspacing="0">\n'
        + '<thead>\n'
        + header
        + '</thead>\n'
        + body
        + '</table>\n</div>';
    }
    html = marked(mdData, { "renderer":renderer }).replace(/src="/g, '$&'+path);
    return { "html":html, "hlist":hlist, "info":info };
}
