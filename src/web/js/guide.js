require.config({
   paths: {
     "marked": "/usr/share/javascript/marked/marked.min",
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
    addhtmlapp();
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

//手册dbus跳转页面js接口函数
function qt_jumpApp(appName)
{
    //去掉传过来字段两端的空格
    appName = appName.trim()
    //判断是否是需要跳转标题的字段
    if(appName.search("/") > 0)
    {
        //处理字段可能开头就是"/"的情况
        if(appName.indexOf("/") == 0){
            appName = appName.slice(1,appName.length)
        }
        //截取跳转的app手册内容和显示app内容后的标题
        var list = appName.split("/")
        if(list.length == 2){
            //跳转app手册内容页面
            onclickButton(list[0])
            //页面的资源都加载完成后跳转需要的标题
            $(document).ready(function(){
                switch (list[1]){
                    case "mate-calc":
                        document.getElementById("list_h10").click()
                        break;
                    case "ukui-system-monitor":
                        document.getElementById("list_h1").click()
                        break;
                    case "onboard":
                        document.getElementById("list_h23").click()
                        break;
                    case "cheese":
                        document.getElementById("list_h6").click()
                        break;
                    case "gnome-screenshot":
                        document.getElementById("list_h16").click()
                        break; 
                    default:
                        break;
                }
            });
        }    
    }
    else
        onclickButton(appName);
}

var date ={
    kylinOS:"2020年3月24日",
    ukui:"2020年3月23日",
    // kydroid2:"2019年11月13日",
    ukui_control_center : "2020年3月21日",
    biometric_manager : "2020年3月18日",
    hot_key:"2020年3月20日",
    peony:"2020年3月14日",
    ubuntu_kylin_software_center:"2020年3月20日", 
    kylin_video:"2020年3月20日",
    burner:"2020年3月20日",
    kylin_assistant:"2020年3月20日",
    indicator_china_weather:"2020年3月20日",
    // kylin_ipmsg:"2019年11月13日",
    // kysec_ui_pkexec:"2019年11月13日",
    // kybackup:"2019年11月13日",
    // audacious:"2019年11月13日",
    eom :"2020年3月20日",
    // kylin_update_manager:"2019年11月13日",
    remmina:"22020年3月20日",
    // vino_preferences:"2019年11月13日",
    // claws_mail:"2019年11月13日",
    // system_config_printer:"2019年11月13日",
    // simple_scan:"2019年11月13日",
    // mate_system_monitor:"2019年11月13日",
    // gparted:"2019年11月13日",
    engrampa:"2020年3月20日",
    // audio_recorder:"2019年11月13日",
    mate_terminal:"2020年3月20日",
    tools:"2020年3月13日",
    technical_assistance:"2020年3月24日",
};

function onclickButton(str)
{
//    alert(str)
    //console.log(str+"======"+window.pageYOffset);
    document.getElementById("mainUI").style.display="none";
    document.getElementById("pageContent").style.display="inline";

    var mdPath = window.guideWebkit.js_getIndexMdFilePath(str)
    var mdDate = window.guideWebkit.js_getIndexMdFileContent(mdPath)
    //console.log(str,mdPath);
//    alert(mdDate)
    var m2ht = getDocTop(mdPath,mdDate)
    var html = m2ht.html
    var hlist = m2ht.hlist
    var info = m2ht.info
    //console.log(html);
    //console.log("--------------------------------------hlist");
    //console.log(hlist);
    //console.log("--------------------------------------info");
    //console.log(info);
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
        //console.log(hlist[i].type+"======"+name_text);
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
            //console.log(name_text.length);
            if(name_text.length >12)
            {
                hlist_str +=  "<dt>\n" + "<a class='name3' style='line-height:20px;' onclick=onclickA('list_"+hlist[i].id+"')"+" id=" + "list_"+hlist[i].id + " href=\'#" +hlist[i].id + "\'>" + name_text + "</a> \n</dt>" ;
            }
            else
            {
                hlist_str +=  "<dt>\n" + "<a class='name3' onclick=onclickA('list_"+hlist[i].id+"')"+" id=" + "list_"+hlist[i].id + " href=\'#" +hlist[i].id + "\'>" + name_text + "</a> \n</dt>" ;
            }
            //console.log(hlist_str);
        }   
     }
     hlist_str = "<dl>" + hlist_str + "</dl>";
 //   console.log(hlist_str);
    str_name = str.replace(/-/g,"_"); 
    if(navigator.language=="zh-CN")
    {
        var update="更新时间："
        var goTop="返回顶部"
        var Data=date[str_name]
    }
    else
    {
        var update="Update："
        var goTop="Go Top"
        var Data=date[str_name].replace(/[\u4e00-\u9fa5]/g,".")
        Data=Data.slice(0,Data.length-1)
    }
    html_new = "<h1><a name='paga_top'>"+info.title+"</a></h1>"
                                +"<p  class='date' style='text-indent: 0px;'>"
                                +update
                                +Data
                                +"</p>"
                                +"<HR style='margin-bottom: 34px;margin-top: 10px'>"
                                +html
                                +"<HR style='margin-top: 20px'>"
                                +"<div class='paga_top' >"
                                +"<img src='file:////usr/share/kylin-user-guide/data/icon-go-top.png' "+"/>"
                                +"<a style='text-decoration: none;'onclick=onclickA('') href='#paga_top'>"
                                +goTop
                                +"</a>"
                                +"</div>"
                                //+"<div id='top'>"
                                //+"<img src='file:////usr/share/kylin-user-guide/data/go-top.png' "+"/>"
                                //+"</div>"

    document.getElementById("hlist").innerHTML = hlist_str
    document.getElementById("content").scrollTop = 0;
    document.getElementById("content").innerHTML = html_new
    

}

function getapp_name(qpp)
{
    var dirforapp
    var mdPath = window.guideWebkit.js_getIndexMdFilePathOther(qpp)
    var mdDate = window.guideWebkit.js_getIndexMdFileContent(mdPath)

    console.log(mdPath)
    if(navigator.language=="zh-CN")
    {
        if(mdPath.search("/guide/")>0)
        {
            dirforapp="guide"
        }
        else if(mdPath.search("/guide-ubuntukylin/")>0)
        {
            dirforapp="guide-ubuntukylin"
        }
        var info = window.guideWebkit.js_getIndexMdFileTitle(mdPath)
        // console.log(window.guideWebkit.js_getIndexMdFileTitle(mdPath))  
        //console.log(info+"======"+qpp)
        if(info.search("帮助手册")<0)
        {
            return info+"|"+dirforapp;
        }
        else
        {
            //console.log(info.title.slice(0,info.title.search("帮助手册")))
            return info.slice(0,info.search("帮助手册"))+"|"+dirforapp
        }
    }
    else
    {
        if(mdPath.search("/guide/")>0)
        {
            dirforapp="guide"
        }
        else if(mdPath.search("/guide-ubuntukylin/")>0)
        {
            dirforapp="guide-ubuntukylin"
        }
        return dirforapp
    }
}

function addhtmlapp()
{
    var test=window.guideWebkit.js_getIntoFilename();
    var systemName = window.guideWebkit.JudgmentSystrm();
    if(systemName != "Ubuntu Kylin"){
        document.getElementById("support").style.display="none";
        document.getElementById("sup").style.display="none";
    }
    for(i=0;i<test.length;i++)
    {
        var dirname=test[i].slice(0,test[i].indexOf("|"))
        var pngname=test[i].slice(test[i].indexOf("|")+1,test[i].length)
        if(dirname=="software-compatibility"||dirname=="technical-assistance"
           ||dirname=="kylinOS"||dirname=="ukui"||dirname=="ukui-control-center"
           ||dirname=="biometric-manager"||dirname=="hot-key"
           ||dirname=="hardware-compatibility"
           ||dirname=="ubiquity"||dirname=="kydroid2")
        {
            continue
        }
        else
        {
            if(navigator.language=="zh-CN")
            {
                var NameAndDir=getapp_name(dirname);
                var realname=NameAndDir.slice(0,NameAndDir.indexOf("|"));
                var dir=NameAndDir.slice(NameAndDir.indexOf("|")+1,NameAndDir.length)
            }
            else
            {
                var NameAndDir=getapp_name(dirname);
                var dir=NameAndDir
                realname=dirname.replace(dirname[0],dirname[0].toUpperCase())
                // while(realname.search("-") !== -1)
                // {
                //     realname=realname.replace(realname[realname.indexOf("-")+1],realname[realname.indexOf("-")+1].toUpperCase())
                //     realname=realname.replace("-"," ")
                // }
                if(realname.search("-") !== -1){
                    realname=realname.split("-")
                    if(realname.length == 2){
                        realname[1] = realname[1].replace(realname[1][0],realname[1][0].toUpperCase())
                    }
                    else if(realname.length == 3){
                        realname[1] = realname[1].replace(realname[1][0],realname[1][0].toUpperCase())
                        realname[2] = realname[2].replace(realname[2][0],realname[2][0].toUpperCase())
                    }
                    else if(realname.length == 4){
                        realname[1] = realname[1].replace(realname[1][0],realname[1][0].toUpperCase())
                        realname[2] = realname[2].replace(realname[2][0],realname[2][0].toUpperCase())
                        realname[3] = realname[3].replace(realname[3][0],realname[3][0].toUpperCase())
                    }
                    realname = realname.join(" ")
                }
            }
            var element=document.getElementById("app");
            var para=document.createElement("div")
            var node1=document.createElement("br")
            var node2=document.createElement("img")
            var node3=document.createElement("span")
            var apptext=document.createTextNode(realname)
            var attr=document.createAttribute("onclick")
            attr.value="onclickButton('"+dirname+"')"
            node3.appendChild(apptext)
            node3.style.lineHeight="10px"
            node2.src="file:////usr/share/kylin-user-guide/data/"+dir+"/"+dirname+"/"+pngname+""
            node2.alt=dirname
            para.id="user";
            para.style.marginLeft="26px";
            para.className="system-app";
            //para.onclick(onclickButton('biometric-manager'))
            para.setAttributeNode(attr)
            para.appendChild(node2)
            para.appendChild(node1)
            para.appendChild(node3)
            element.appendChild(para)
        }
    }
}

function goBackMainUI()
{
    //alert(str)
    //console.log(str)
    //document.getElementById("mainUI").style.display="inline";
    //document.getElementById("pageContent").style.display="none";
    if(navigator.language=="zh-CN")
    {
        window.location.href="index.html"
    }
    else
    {
        window.location.href="index_en_US.html"
    }
}

function goBackMainUI_ubuntu()
{
    if(navigator.language=="zh-CN")
    {
        window.location.href="index-ubuntukylin.html"
    }
    else
    {
        window.location.href="index-ubuntukylin_en_US.html"
    }
}

var arrows_div={
    system:0,
    app:0,
    support:0,
}

var  arrows_png={
    button1:0,
    button2:0,
    button3:0,
}

function change_arrows(button_name)
{
    if(arrows_png[button_name] == 0)
    {
        document.getElementById(button_name).style.backgroundImage="url("+"/usr/share/kylin-user-guide/data/arrows_right.png"+")";
        document.getElementById(button_name).style.backgroundSize="20px 20px";
        arrows_png[button_name]=1;
        return
    }
    if(arrows_png[button_name] == 1)
    {
        document.getElementById(button_name).style.backgroundImage="url("+"/usr/share/kylin-user-guide/data/arrows_bottom.png"+")";
        document.getElementById(button_name).style.backgroundSize="20px 20px";
        arrows_png[button_name]=0;
        return
    }
}

function onclickarrows(str)
{
    //console.log(str)
    if(str == 'system') 
    {
        if(arrows_div[str] == 0)
        {
            document.getElementById(str).style.display="none"
            arrows_div.system=1;
        }
        else
        {
            document.getElementById(str).style.display="inline"
            arrows_div.system=0; 
        }
    }
    else if(str == 'app')
    {
        if(arrows_div[str] == 0 )
        {
            document.getElementById(str).style.display="none"
            arrows_div.app=1;
        }
        else
        {
            document.getElementById(str).style.display="inline"
            arrows_div.app=0;
        }
    }
    else if(str == 'support')
    {
        if(arrows_div[str] == 0 )
        {
            document.getElementById(str).style.display="none"
            arrows_div.support=1;
        }
        else
        {
            document.getElementById(str).style.display="inline"
            arrows_div.support=0;
        }
    }
       
}

var old_str="";
function onclickA(str)
{
     //console.log(old_str,str) 
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
            //console.log(logo);
            info = { "title":title, "logo":logo };
            return "";
        }
        if (level == 2) {
            text = text.split('|')[0];
            //console.log(text);
        }
        var type = 'h' + level;
        if (level == 2 || level == 3) {
            hlist.push({ "id":id, "text":text, "type":type });
            //console.log(id);
            //console.log(text);
            //console.log(type);
        }
            return "<"+ type + " id="+   id + " text=" +text + " class='html_h5'>" + text + "</"+ type + ">\n";
    };

    renderer.image = function(href, title, text){
        var hrefX2 = href;
        //console.log(hrefX2);
//         if (devicePixelRatio >= 1.5 && href.indexOf('.svg') == -1) {
//             var path = href.split('.');
//             var ext = path.pop();
// //            hrefX2 = `${path.join('.')}x2.${ext}`;
//             hrefX2 =  path.join('.')+ "x2." + ext;
//         }
        if (text == "")
//            return `<img src="${hrefX2}" data-src="${href}" alt="${text}" />`;
            return '<img src=\"' + hrefX2 + '\" data-src=\"'+ href + '\" alt=' + text +  '/>';
        else{
            if(text.lastIndexOf("-big") < 0 ){
//                return `<h5  style="text-align: center;"><img src="${hrefX2}" data-src="${href}" alt="${text}" /><br>${text}</h5>`;
                return '<h5  style="text-align: center;font-family: Noto Sans SC; font-size: 12px;color=#333333;"><img src=\"' + hrefX2 + '\" data-src=\"' + href + '\" alt=' + text + '/><br> ' + text + '</h5>';
            }
            else{
                text1=text.slice(0,text.lastIndexOf("-big"))
//路径需要用双引号，单引号无法解析相对路径
//                return `<h5 style="text-align: center;"><img  style="height:98%;width:98%;" src="${hrefX2}" data-src="${href}" alt="${text}" /><br>${text1}</h5>`;
                return '<h5 style="text-align: center;font-family: Noto Sans SC; font-size: 12px;color=#333333;"><img  style="height:98%;width:98%;" src=\"' + hrefX2 + '\" data-src=\"' + href + '\" alt='+ text +'/><br>' + text1 + '</h5>';
            }
        }
    };
    renderer.table = function(header,body){
        //console.log(header,body)
        if (body) body = '<tbody>' + body + '</tbody>';
        return '<div align="center"style="font-family:Noto Sans SC;font-size: 12px;"><table border=black cellspacing="0" width="90%">\n'
        + '<thead>\n'
        + header
        + '</thead>\n'
        + body
        + '</table>\n</div>';
    }
    html = marked(mdData, { "renderer":renderer }).replace(/src="/g, '$&'+path);
    return { "html":html, "hlist":hlist, "info":info };
}
