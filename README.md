# Team Portfolio Website

A stunning, modern portfolio website showcasing your team of 4 members with high-end animations and beautiful design.

## Features

- **Landing Page**: Eye-catching hero section with animated gradient background and floating elements
- **Team Page**: Showcase all team members with interactive cards
- **Individual Member Pages**: Detailed profiles highlighting each member's contributions and skills
- **High-End Animations**: Smooth transitions, fade-ins, floating elements, and gradient shifts
- **Responsive Design**: Works beautifully on all devices
- **Modern Tech Stack**: Built with React, TypeScript, and Tailwind CSS

## Getting Started

### Installation

```bash
npm install
```

### Development

The development server starts automatically. Your site will be available at the local URL.

### Build for Production

```bash
npm run build
```

## Customization

### Update Team Member Information

Edit the file `src/data/teamData.ts` to customize your team members:

```typescript
{
  id: 1,
  name: "Your Name",
  role: "Your Role",
  bio: "Your bio description",
  image: "https://your-image-url.com/photo.jpg",
  contributions: [
    "Your contribution 1",
    "Your contribution 2"
  ],
  skills: ["Skill 1", "Skill 2", "Skill 3"],
  email: "your.email@example.com",
  github: "yourgithub"
}
```

### Change Team Name

Update the team name in `src/components/LandingPage.tsx` (line 13):

```typescript
<span>TeamForce</span> // Change this to your team name
```

### Modify Colors

The color scheme uses cyan and blue tones. To change colors, update the Tailwind classes in the components:

- Main accent: `cyan-400`, `cyan-500`, `blue-500`, `blue-600`
- Search for these classes in the component files to update

### Change Animations

All animations are defined in `src/index.css`. You can:
- Adjust animation durations
- Modify animation keyframes
- Add new animations

## Project Structure

```
src/
├── components/
│   ├── LandingPage.tsx      # Main landing page
│   ├── TeamPage.tsx          # Team members overview
│   └── MemberPage.tsx        # Individual member details
├── data/
│   └── teamData.ts           # Team member information
├── types.ts                  # TypeScript interfaces
├── App.tsx                   # Main app with routing
└── index.css                 # Animations and styles
```

## Deployment to GitHub Pages

1. **Build the project**:
   ```bash
   npm run build
   ```

2. **The `dist` folder** contains your production-ready website

3. **Deploy to GitHub Pages**:
   - Go to your GitHub repository
   - Settings → Pages
   - Source: Deploy from a branch
   - Select the branch containing your `dist` folder
   - Save

Alternatively, you can use GitHub Actions for automatic deployment.

## Technologies Used

- **React**: UI library
- **TypeScript**: Type-safe development
- **Tailwind CSS**: Utility-first styling
- **Vite**: Fast build tool
- **Lucide React**: Beautiful icons

## License

Free to use for educational and portfolio purposes.
