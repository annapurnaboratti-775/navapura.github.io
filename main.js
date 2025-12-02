// Parallax background subtle (hero)
(function(){
  // small floating motion for right-hand cards
  const cards = document.querySelectorAll('.floating-card, .team-card');
  window.addEventListener('mousemove', (e) => {
    const x = (e.clientX / window.innerWidth) - 0.5;
    const y = (e.clientY / window.innerHeight) - 0.5;
    document.querySelectorAll('.logo-blob').forEach(el => {
      el.style.transform = `translate(${x*6}px, ${y*6}px) rotate(${x*4}deg)`;
    });
    cards.forEach((c, i) => {
      const depth = (i%3) + 1;
      c.style.transform = `translate3d(${x*8/depth}px, ${y*8/depth}px, 0)`;
    });
  });

  // Smooth reveal for team cards
  const obs = new IntersectionObserver(entries => {
    entries.forEach(en => {
      if(en.isIntersecting) en.target.classList.add('visible');
    });
  }, {threshold: 0.12});
  document.querySelectorAll('.team-card').forEach(c => obs.observe(c));

  // tiny hover pop on buttons
  document.querySelectorAll('.btn').forEach(b => {
    b.addEventListener('mouseenter', () => b.style.transform = 'translateY(-4px)');
    b.addEventListener('mouseleave', () => b.style.transform = '');
  });
})();
