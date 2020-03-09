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

function onclickButton(str)
{
//    alert(str)
    console.log(str)
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
        console.log(hlist[i].type);
        if(hlist[i].type == "h1")
            hlist_str +=  "<h1>\n" + "<a id=" + "list_"+hlist[i].id + " href=\'#" +hlist[i].id + "\'>" + hlist[i].text + "</a> \n</h1>" ;
        else if(hlist[i].type == "h2")
            hlist_str +=  "<h2>\n" + "<a id=" + "list_"+hlist[i].id + " href=\'#" +hlist[i].id + "\'>" + hlist[i].text + "</a> \n</h2>" ;
        else if(hlist[i].type == "h3")
        {
            hlist_str +=  "<h3>\n" + "<a id=" + "list_"+hlist[i].id + " href=\'#" +hlist[i].id + "\'>" + hlist[i].text + "</a> \n</h3>" ;
            console.log(hlist_str);
        }
     }
 //   console.log(hlist_str);

    html_new = "<h1><a name='paga_top'>"+info.title+"</a></h1>"
                                +"<p  style='text-align: left;font-size: 10px;text-indent: 0px;'>更新时间：****年**月**日</p>"
                                +"<HR style='margin-bottom: 34px;margin-top: 10px'>"
                                +html
                                +"<HR style='margin-top: 20px'>"
                                +"<a style='text-align: right;margin-top: 20px;margin-bottom: 50px;'  href='#paga_top'>返回顶部</a>"

    document.getElementById("hlist").innerHTML = hlist_str
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
            return "<"+ type + " id="+   id + " text=" +text + ">" + text + "</ "+ type + ">\n";
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
    /*renderer.table = (header,body) =>{
        console.log(header,body)
        if (body) body = '<tbody>' + body + '</tbody>';
        return '<div align="center"><table border=black cellspacing="0">\n'
        + '<thead>\n'
        + header
        + '</thead>\n'
        + body
        + '</table>\n</div>';
    }*/
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
