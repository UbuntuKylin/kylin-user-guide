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

var html_list={
    onboard:"list_h1",
    atril:"list_h2",
    indicator_china_weather:"list_h4",
    kylin_recorder:"list_h5",
    kylin_usb_creator:"list_h6",
    kylin_screenshot:"list_h7",
    kylin_calculator:"list_h8",
    kylin_camera:"list_h9",
    kylin_scanner:"list_h10",
    gnome_tetravex:"list_h1",
    gnome_mines:"list_h2",
    iagno:"list_h3",
};

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
            
            //将“-”转换成“_”
            if(list[1].search("-")>0){
                list[1] = list[1].replace(/-/g,"_");
            }
            
            //页面的资源都加载完成后跳转需要的标题
            $(document).ready(function(){
                    var target = html_list[list[1]]
                    document.getElementById(target).click()
            });
        }    
    }
    else
        onclickButton(appName);
}

var date ={
    biometric_manager:"2021年2月22日",
    box_manager:"2021年2月22日",
    claws_mail:"2021年2月22日",
    engrampa:"2021年2月22日",
    eom:"2021年2月22日",
    filezilla:"2021年2月22日",
    game:"2021年2月22日",
    gparted:"2021年2月22日",
    hot_key:"2021年2月22日",
    ksc_defender:"2021年2月22日",
    kybackup:"2021年2月22日",
    kylin_assistant:"2021年2月22日",
    kylin_burner:"2021年2月22日",
    kylin_ipmsg:"2021年2月22日",
    kylin_music:"2021年2月22日",
    kydroid:"2021年2月22日",
    kylin_log_viewer:"2021年2月22日",
    kylinOS:"2021年2月22日",
    kylin_service_support:"2021年1月29日",
    kylin_store:"2021年2月22日", 
    kylin_video:"2021年2月22日",
    mate_terminal:"2021年2月22日",
    peony:"2021年2月22日",
    recoll:"2021年2月22日",
    remmina:"2021年2月22日",
    technical_assistance:"2021年2月22日",
    tools:"2021年2月22日",
    kylin_os_installer:"2021年2月22日",
    ukui:"2021年2月22日",
    ukui_control_center:"2021年2月22日",
    kylin_system_monitor:"2021年2月22日",
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
            if(name_text.length >= 11)
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
            if(name_text.length >= 11)
            {
                hlist_str +=  "<dt>\n" + "<a class='name2' style='line-height:20px;' onclick=onclickA('list_"+hlist[i].id+"')"+" id=" + "list_"+hlist[i].id + " href=\'#" +hlist[i].id + "\'>" + name_text + "</a> \n</dt>" ;
            }
            else
            {
                hlist_str +=  "<dt>\n" + "<a class='name2' onclick=onclickA('list_"+hlist[i].id+"')"+" id=" + "list_"+hlist[i].id + " href=\'#" +hlist[i].id + "\'>" + name_text + "</a> \n</dt>" ;
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
        document.getElementById("kylinOS").style.display="none";
    }
    // if(window.guideWebkit.js_getCpuArchitecture()){
    //     document.getElementById("kydroid").style.display="none";
    // }
    for(i=0;i<test.length;i++)
    {
        var dirname=test[i].slice(0,test[i].indexOf("|"))
        var pngname=test[i].slice(test[i].indexOf("|")+1,test[i].length)
        if(dirname=="software-compatibility"||dirname=="technical-assistance"
           ||dirname=="kylinOS"||dirname=="ukui"||dirname=="ukui-control-center"
           ||dirname=="hot-key"
           ||dirname=="hardware-compatibility"
           ||dirname=="kylin-os-installer")
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

var style_name
function SwitchStyle(id)
{
    // for(var i=1;i<2;i++)
    // {
    //     if(i==id)
    //         document.getElementById("css"+i).disabled = false;
    //     else
    //         document.getElementById("css"+i).disabled = true;
    // }
    var css = document.getElementById("css")
    if(id == 1){
        css.setAttribute("href","css/guide-white.css");
        style_name = 1
	clearAllDtAttr()
    }else{
        css.setAttribute("href","css/guide-black.css");
        style_name = 2
	clearAllDtAttr()
    }
}

function clearAllDtAttr()
{
        var dt_list = document.getElementsByTagName("dt")
        if(dt_list.length > 0){
		for(let i = 0 ;i < dt_list.length; i++ ){
			let elem = dt_list[i].children
			if(elem[0].hasAttribute("style")){
		                elem[0].removeAttribute("style")
				Refresh_the_content_interface()
			}
			
		}
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

var arrows_big_png={
    width:0,
    height:0,
}

var arrows_png={
    button1:0,
    button2:0,
    button3:0,
}

function change_arrows(button_name)
{
    if(arrows_png[button_name] == 0)
    {
        document.getElementById(button_name).style.backgroundImage="url("+"/usr/share/icons/ukui-icon-theme-default/scalable/actions/pan-end-symbolic.svg"+")";
        document.getElementById(button_name).style.backgroundSize="20px 20px";
        arrows_png[button_name]=1;
        return
    }
    if(arrows_png[button_name] == 1)
    {
        document.getElementById(button_name).style.backgroundImage="url("+"/usr/share/icons/ukui-icon-theme-default/scalable/actions/pan-down-symbolic.svg"+")";
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
        if(style_name == 1){
            document.getElementById(old_str).style.backgroundColor="rgb(231,231,231)" 
            document.getElementById(old_str).style.color="black"
        }else{
            document.getElementById(old_str).style.backgroundColor="rgb(29,29,31)" 
            document.getElementById(old_str).style.color="white"
        }
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

function Refresh_the_content_interface()
{   
    if(old_str != ""){
    	document.getElementById(old_str).click()
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
                var size = window.guideWebkit.js_getBigPngSize(path+hrefX2);
                if(size[0]!=0&&size[1]!=0)
                return '<h5 style="text-align: center;font-family: Noto Sans SC; font-size: 12px;color=#333333;"><img  style="height:98%;width:98%;max-width:'+size[0] + 'px;max-height:'+size[1] +'px;" src=\"' + hrefX2 + '\"" data-src=\"' + href + '\" alt='+ text +'/><br>' + text1 + '</h5>';
                else
                return '<h5 style="text-align: center;font-family: Noto Sans SC; font-size: 12px;color=#333333;"><img  style="height:98%;width:98%;" src=\"' + hrefX2 + '\"" data-src=\"' + href + '\" alt='+ text +'/><br>' + text1 + '</h5>';
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
