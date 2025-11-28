// main.js - parallax, tilt cards, reveal-on-scroll, mobile nav
(function(){
  // Parallax: move layers on mouse and scroll
  const parallax = document.querySelector('.parallax');
  if(parallax){
    window.addEventListener('mousemove', (e) => {
      const x = (e.clientX / window.innerWidth - 0.5) * 30;
      const y = (e.clientY / window.innerHeight - 0.5) * 20;
      parallax.querySelectorAll('.layer').forEach((el, i) => {
        const depth = (i+1) * 1.6;
        el.style.transform = `translate3d(${x/depth}px, ${y/depth}px, 0)`;
      });
    });

    // small scroll parallax
    window.addEventListener('scroll', () => {
      const sc = window.scrollY;
      parallax.querySelector('.bg').style.transform = `translateY(${sc * -0.03}px)`;
      parallax.querySelector('.mid').style.transform = `translateY(${sc * -0.06}px)`;
      parallax.querySelector('.fore').style.transform = `translateY(${sc * -0.12}px)`;
    });
  }

  // Tilt effect for cards (mouse)
  const tiltable = document.querySelectorAll('[data-tilt]');
  tiltable.forEach(el => {
    el.addEventListener('mousemove', (e) => {
      const r = el.getBoundingClientRect();
      const px = (e.clientX - r.left) / r.width;
      const py = (e.clientY - r.top) / r.height;
      const rx = (py - 0.5) * -8;
      const ry = (px - 0.5) * 12;
      el.style.transform = `perspective(700px) rotateX(${rx}deg) rotateY(${ry}deg) translateZ(6px)`;
      el.style.boxShadow = '0 18px 40px rgba(0,0,0,0.55)';
    });
    el.addEventListener('mouseleave', () => {
      el.style.transform = '';
      el.style.boxShadow = '';
    });
  });

  // Reveal on scroll
  const observer = new IntersectionObserver((entries) => {
    entries.forEach(ent => {
      if(ent.isIntersecting){
        const el = ent.target;
        const delay = el.getAttribute('data-delay') || 0;
        setTimeout(() => el.classList.add('show'), Number(delay));
        observer.unobserve(el);
      }
    });
  }, {threshold: 0.12});

  document.querySelectorAll('.reveal').forEach(e => observer.observe(e));

  // small reveal for feature cards
  document.querySelectorAll('.feature').forEach((f, i) => {
    f.setAttribute('data-delay', i*120);
    observer.observe(f);
  });

  // Mobile nav toggle
  const navToggle = document.getElementById('navToggle');
  const navLinks = document.getElementById('navLinks');
  navToggle && navToggle.addEventListener('click', () => {
    if(navLinks.style.display === 'flex') {
      navLinks.style.display = '';
    } else {
      navLinks.style.display = 'flex';
      navLinks.style.flexDirection = 'column';
      navLinks.style.gap = '10px';
      navLinks.style.padding = '14px';
      navLinks.style.background = 'linear-gradient(180deg, rgba(7,16,23,0.9), rgba(7,16,23,0.96))';
      navLinks.style.position = 'absolute';
      navLinks.style.right = '18px';
      navLinks.style.top = '62px';
      navLinks.style.borderRadius = '12px';
      navLinks.style.boxShadow = '0 16px 40px rgba(0,0,0,0.6)';
    }
  });

  // Smooth anchor scrolling (if linking to internal sections)
  document.querySelectorAll('a[href^="#"]').forEach(anchor => {
    anchor.addEventListener('click', function(e){
      e.preventDefault();
      const target = document.querySelector(this.getAttribute('href'));
      if(target) target.scrollIntoView({behavior:'smooth', block:'start'});
    });
  });

})();
