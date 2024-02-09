(()=>{function S(t){let e=t.getAttribute("aria-controls"),o=document.getElementById(e),c="data-expanded-"+e;t.addEventListener("click",function(){document.body.hasAttribute(c)?(document.body.removeAttribute(c),o.classList.remove("_expanded"),f(e,"false")):(document.body.setAttribute(c,"true"),o.classList.add("_expanded"),f(e,"true"))})}function f(t,e){let o=document.querySelectorAll('[aria-controls="'+t+'"]');for(el of o)el.setAttribute("aria-expanded",e)}var b=document.querySelectorAll(".js-menu");for(let t=0;t<b.length;t++)S(b[t]);var i=document.querySelector(".announcement"),L=document.querySelector(".announcement-close");if(i){let e=function(){t.textContent=`:root{--sy-s-banner-height:${i.clientHeight}px}`};v=e;let t=document.createElement("style");document.head.appendChild(t),L.addEventListener("click",()=>{i.parentNode.removeChild(i),document.head.removeChild(t)}),e(),window.addEventListener("resize",e)}var v;var l=["auto","light","dark"],a=l.indexOf(sessionStorage._theme||"auto"),d=document.querySelector(".js-theme");function x(){a+=1,l[a]||(a=0);let t=l[a];setColorMode(t),sessionStorage._theme=t,h(t)}function h(t){let e=d.getAttribute("data-aria-"+t);d.setAttribute("aria-label",e)}d&&(d.addEventListener("click",x),h(l[a]||"auto"));function A(){let t=document.querySelector(".globaltoc");if(!t)return;let e=parseInt(t.getAttribute("data-expand-depth"),10),o=n=>{if(!e)return!1;let s=0;for(;n.parentNode&&n.parentNode!==t;)n=n.parentNode,n.nodeName==="UL"&&(s+=1);return e>=s};t.querySelectorAll("li > ul").forEach(n=>{let s=n.parentNode;s.classList.contains("current")||o(s)?s.classList.add("_expand"):s.classList.add("_collapse");let r=_(n);s.appendChild(r)})}function _(t){let e=document.createElement("button");e.innerHTML='<i class="i-icon chevron"></i>';let o=t.parentNode,c=t.previousSibling,n=c.textContent,s=()=>{o.classList.contains("_expand")?e.setAttribute("arial-label","Collapse "+n):e.setAttribute("arial-label","Expand "+n)};s();let r=y=>{y.preventDefault(),o.classList.contains("_expand")?(o.classList.remove("_expand"),o.classList.add("_collapse")):(o.classList.remove("_collapse"),o.classList.add("_expand")),s()};return c.getAttribute("href")==="#"&&c.addEventListener("click",r),e.addEventListener("click",r),e}A();function g(){let t='.localtoc a[href="'+location.hash+'"]',e=document.querySelector(t);e&&(document.querySelectorAll(".localtoc li").forEach(c=>{c.classList.remove("active")}),e.parentNode.classList.add("active"))}g();window.addEventListener("hashchange",()=>{g()},!1);var u=document.querySelector(".js-repo-stats");async function E(t,e){let o=`https://api.github.com/repos/${t}/${e}`,n=await(await fetch(o)).json(),s={stars:n.watchers,forks:n.forks};p(s),sessionStorage.setItem("_sy/repo/stats",JSON.stringify(s))}async function q(t,e){let o="https://gitlab.com/api/v4/projects/"+encodeURIComponent(t+"/"+e),n=await(await fetch(o)).json(),s={stars:n.star_count,forks:n.forks_count};p(s),sessionStorage.setItem("_sy/repo/stats",JSON.stringify(s))}function p({stars:t,forks:e}){t&&(document.querySelector(".js-repo-stars").textContent=t),e&&(document.querySelector(".js-repo-forks").textContent=e)}function w(){let t=sessionStorage.getItem("_sy/repo/stats");if(t)p(JSON.parse(t));else{let e=u.getAttribute("data-user"),o=u.getAttribute("data-repo"),c=u.getAttribute("data-type");c==="github"?E(e,o):c==="gitlab"&&q(e,o)}}u&&w();function C(t,e){let o=document.createElement("script");o.id="_carbonads_js",o.src=`//cdn.carbonads.com/carbon.js?serve=${t}&placement=${e}`;let c=document.querySelector(".yue > section"),n=document.querySelector(".yue > section > section");if(n)c.insertBefore(o,n);else{let s=document.querySelector(".yue > section > p");s?c.insertBefore(o,s.nextSibling):c.appendChild(o)}}var m=document.querySelector(".js-carbon");if(m){let t=m.getAttribute("data-carbon-code"),e=m.getAttribute("data-carbon-placement");t&&e&&C(t,e)}/windows/i.test(navigator.userAgent)&&document.body.classList.add("win");})();